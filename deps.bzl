load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def _sfml_ext_impl(module_ctx):
    http_archive(
        name = "sfml_bin",
        urls = ["https://github.com/SFML/SFML/releases/download/3.0.1/SFML-3.0.1-linux-gcc-64-bit.tar.gz"],
        strip_prefix = "SFML-3.0.1",
    )

sfml_ext = module_extension(
    implementation = _sfml_ext_impl,
)
