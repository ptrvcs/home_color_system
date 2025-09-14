load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def _sdl2_ext_impl(module_ctx):
    http_archive(
        name = "sdl2",
        urls = ["https://github.com/libsdl-org/SDL/releases/download/release-2.30.5/SDL2-2.30.5.tar.gz"],
        strip_prefix = "SDL2-2.30.5",
        build_file = "//third_party/sdl2:BUILD.bazel",
    )

sdl2_ext = module_extension(
    implementation = _sdl2_ext_impl,
)
