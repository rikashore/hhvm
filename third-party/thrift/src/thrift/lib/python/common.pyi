# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from enum import Enum
from typing import Iterator, Mapping

from thrift.python.protocol import Protocol as Protocol_

Protocol = Protocol_

class Priority(Enum):
    HIGH_IMPORTANCE: Priority = ...
    HIGH: Priority = ...
    IMPORTANT: Priority = ...
    NORMAL: Priority = ...
    BEST_EFFORT: Priority = ...
    N_PRIORITIES: Priority = ...
    @property
    def value(self) -> int: ...

class Headers(Mapping[str, str]):
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __contains__(self, o: object) -> bool: ...
    def __getitem__(self, key: str) -> str: ...
    def __iter__(self) -> Iterator[str]: ...

class ReadHeaders(Headers): ...
class WriteHeaders(Headers): ...

class RpcOptions:
    @property
    def timeout(self) -> float: ...
    @timeout.setter
    def timeout(self, seconds: float) -> None: ...
    @property
    def priority(self) -> Priority: ...
    @priority.setter
    def priority(self, value: Priority) -> None: ...
    @property
    def chunk_timeout(self) -> float: ...
    @chunk_timeout.setter
    def chunk_timeout(self, seconds: float) -> None: ...
    @property
    def queue_timeout(self) -> float: ...
    @queue_timeout.setter
    def queue_timeout(self, seconds: float) -> None: ...
    @property
    def chunk_buffer_size(self) -> int: ...
    @chunk_buffer_size.setter
    def chunk_buffer_size(self, buffer_size: int) -> int: ...
    def memory_buffer_size(
        self, buffer_size: int, initial_chunks: int, max_chunks: int
    ) -> int: ...
    def set_header(self, key: str, value: str) -> None: ...
    @property
    def read_headers(self) -> ReadHeaders: ...
    @property
    def write_headers(self) -> WriteHeaders: ...
