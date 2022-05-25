// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.

use std::fmt;

use ocamlrep::{FromOcamlRep, FromOcamlRepIn, ToOcamlRep};
use serde::{Deserialize, Serialize};

use crate::file_pos::FilePos;

// Three values packed into one 64-bit integer:
//
//    6         5         4         3         2         1         0
// 3210987654321098765432109876543210987654321098765432109876543210
// X<----------------------------><----------------------><------->
//        beginning of line                 line            column
//
// - (X)    This bit left empty for OCaml's tagged integer representation
//          (1 if int, 0 if pointer). OCaml uses the least significant bit
//          for this rather than the most significant, but conversion code
//          (e.g., code generated by deriving OcamlRep) will shift the value
//          left and set the tag bit for us.
// - (bol)  beginning of line (byte offset from start of file) starts at 0,
//          maximum is 2^30-1 = 1,073,741,823
// - (line) line number starts at 1, maximum is 2^24-1 = 16,777,215
// - (col)  column number starts at 0, maximum is 2^9-1 = 511
//            This is saturating, i.e. every column past 511 has column
//            number 511 (so as not to raise exceptions).
#[derive(Copy, Clone, Deserialize, Hash, Eq, PartialEq, Serialize)]
pub struct FilePosSmall(u64);

arena_deserializer::impl_deserialize_in_arena!(FilePosSmall);

impl arena_trait::TrivialDrop for FilePosSmall {}

const COLUMN_BITS: usize = 9;
const LINE_BITS: usize = 24;
const BOL_BITS: usize = 30;

#[inline]
const fn mask(bits: usize) -> usize {
    (1 << bits) - 1
}

#[inline]
const fn mask_by(bits: usize, x: u64) -> usize {
    (x & (mask(bits) as u64)) as usize
}

const MAX_COLUMN: usize = mask(COLUMN_BITS);
const MAX_LINE: usize = mask(LINE_BITS);
const MAX_BOL: usize = mask(BOL_BITS);

const DUMMY: u64 = u64::max_value();

impl FilePosSmall {
    #[inline]
    pub const fn make_dummy() -> Self {
        FilePosSmall(DUMMY)
    }

    #[inline]
    pub const fn is_dummy(self) -> bool {
        self.0 == DUMMY
    }

    #[inline]
    pub fn beg_of_line(self) -> usize {
        if self.is_dummy() {
            0
        } else {
            mask_by(BOL_BITS, self.0 >> (LINE_BITS + COLUMN_BITS)) as usize
        }
    }

    #[inline]
    pub fn line(self) -> usize {
        if self.is_dummy() {
            0
        } else {
            mask_by(LINE_BITS, self.0 >> COLUMN_BITS) as usize
        }
    }

    #[inline]
    pub fn column(self) -> usize {
        if self.is_dummy() {
            DUMMY as usize
        } else {
            mask_by(COLUMN_BITS, self.0) as usize
        }
    }

    #[inline]
    const fn bol_line_col_unchecked(bol: usize, line: usize, col: usize) -> Self {
        FilePosSmall(
            ((bol as u64) << (COLUMN_BITS + LINE_BITS))
                + ((line as u64) << COLUMN_BITS)
                + (col as u64),
        )
    }

    #[inline]
    fn bol_line_col(bol: usize, line: usize, col: usize) -> Option<Self> {
        if col > MAX_COLUMN || line > MAX_LINE || bol > MAX_BOL {
            None
        } else {
            Some(Self::bol_line_col_unchecked(bol, line, col))
        }
    }

    #[inline]
    pub const fn beg_of_file() -> Self {
        Self::bol_line_col_unchecked(0, 1, 0)
    }

    // constructors

    #[inline]
    pub fn from_line_column_offset(line: usize, column: usize, offset: usize) -> Option<Self> {
        Self::bol_line_col(offset - column, line, column)
    }

    #[inline]
    pub fn from_lnum_bol_offset(lnum: usize, bol: usize, offset: usize) -> Option<Self> {
        Self::bol_line_col(bol, lnum, offset - bol)
    }

    // accessors

    #[inline]
    pub fn line_beg(self) -> (usize, usize) {
        (self.line(), self.beg_of_line())
    }

    #[inline]
    pub fn line_column(self) -> (usize, usize) {
        (self.line(), self.column())
    }

    #[inline]
    pub fn line_column_offset(self) -> (usize, usize, usize) {
        (self.line(), self.column(), self.offset())
    }

    #[inline]
    pub fn line_beg_offset(self) -> (usize, usize, usize) {
        (self.line(), self.beg_of_line(), self.offset())
    }

    #[inline]
    pub fn with_column(self, col: usize) -> Self {
        match Self::bol_line_col(self.beg_of_line(), self.line(), col) {
            None => FilePosSmall(DUMMY),
            Some(pos) => pos,
        }
    }
}

impl FilePos for FilePosSmall {
    #[inline]
    fn offset(&self) -> usize {
        self.beg_of_line() + self.column()
    }

    #[inline]
    fn line_column_beg(&self) -> (usize, usize, usize) {
        (self.line(), self.column(), self.beg_of_line())
    }
}

impl Ord for FilePosSmall {
    fn cmp(&self, other: &FilePosSmall) -> std::cmp::Ordering {
        self.offset().cmp(&other.offset())
    }
}

impl PartialOrd for FilePosSmall {
    fn partial_cmp(&self, other: &FilePosSmall) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl fmt::Debug for FilePosSmall {
    fn fmt(&self, fmt: &mut fmt::Formatter<'_>) -> fmt::Result {
        fmt.debug_struct("FilePosSmall")
            .field("bol", &self.beg_of_line())
            .field("line", &self.line())
            .field("column", &self.column())
            .finish()
    }
}

impl ToOcamlRep for FilePosSmall {
    fn to_ocamlrep<'a, A: ocamlrep::Allocator>(
        &'a self,
        _alloc: &'a A,
    ) -> ocamlrep::OpaqueValue<'a> {
        ocamlrep::OpaqueValue::int(self.0 as isize)
    }
}

impl FromOcamlRep for FilePosSmall {
    fn from_ocamlrep(value: ocamlrep::Value<'_>) -> Result<Self, ocamlrep::FromError> {
        Ok(Self(ocamlrep::from::expect_int(value)? as u64))
    }
}

impl<'a> FromOcamlRepIn<'a> for FilePosSmall {
    fn from_ocamlrep_in(
        value: ocamlrep::Value<'_>,
        _alloc: &'a ocamlrep::Bump,
    ) -> Result<Self, ocamlrep::FromError> {
        Self::from_ocamlrep(value)
    }
}
