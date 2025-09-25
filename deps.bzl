load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def _qt_ext_impl(module_ctx):
    http_archive(
        name = "qt_bin",
        urls = ["https://github.com/qt/qt/releases/download/3.0.1/qt-3.0.1-linux-gcc-64-bit.tar.gz"],
        strip_prefix = "qt-3.0.1",
    )

qt_ext = module_extension(
    implementation = _qt_ext_impl,
)
