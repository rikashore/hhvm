// @generated by autocargo

use std::env;
use std::fs;
use std::path::Path;
use thrift_compiler::Config;
use thrift_compiler::GenContext;
const CRATEMAP: &str = "\
test_deprecated_optional_with_default_is_some crate //thrift/lib/rust/src/dep_tests:test_deprecated_optional_with_default_is_some_if-rust
";
#[rustfmt::skip]
fn main() {
    println!("cargo:rerun-if-changed=thrift_build.rs");
    let out_dir = env::var_os("OUT_DIR").expect("OUT_DIR env not provided");
    let cratemap_path = Path::new(&out_dir).join("cratemap");
    fs::write(cratemap_path, CRATEMAP).expect("Failed to write cratemap");
    let mut conf = Config::from_env(GenContext::Mocks)
        .expect("Failed to instantiate thrift_compiler::Config");
    let cargo_manifest_dir = env::var_os("CARGO_MANIFEST_DIR")
        .expect("CARGO_MANIFEST_DIR not provided");
    let mut base_path = Path::new(&cargo_manifest_dir)
        .join("../../../../../..")
        .canonicalize()
        .expect("Failed to canonicalize base_path");
    if cfg!(windows) {
        base_path = base_path.to_string_lossy().trim_start_matches(r"\\?\").into();
    }
    conf.base_path(base_path);
    conf.types_crate("test_deprecated_optional_with_default_is_some_if__types");
    conf.clients_crate("test_deprecated_optional_with_default_is_some_if__clients");
    conf.options("deprecated_optional_with_default_is_some");
    let srcs = &["../test_deprecated_optional_with_default_is_some.thrift"];
    conf.run(srcs).expect("Failed while running thrift compilation");
}
