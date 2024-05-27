load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
# load("@bazel_tools//tools/build_defs/repo:local.bzl", "local_repository")
# load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

# buildifier is written in Go and hence needs rules_go to be built.
# See https://github.com/bazelbuild/rules_go for the up to date setup instructions.
http_archive(
    name = "io_bazel_rules_go",
    sha256 = "6dc2da7ab4cf5d7bfc7c949776b1b7c733f05e56edc4bcd9022bb249d2e2a996",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_go/releases/download/v0.39.1/rules_go-v0.39.1.zip",
        "https://github.com/bazelbuild/rules_go/releases/download/v0.39.1/rules_go-v0.39.1.zip",
    ],
)

load("@io_bazel_rules_go//go:deps.bzl", "go_rules_dependencies")

go_rules_dependencies()

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/305e5a238b3c8d11266fbafd85520fb6b3184851.zip"],
  strip_prefix = "googletest-305e5a238b3c8d11266fbafd85520fb6b3184851",
)
http_archive(
    name = "eigen",
    build_file = "@//:eigen/eigen.BUILD",
    urls = ["https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.zip"],
    strip_prefix = "eigen-3.4.0",
    sha256 = "1ccaabbfe870f60af3d6a519c53e09f3dcf630207321dffa553564a8e75c4fc8",
)
# maybe(
#   http_archive,
#   name = "eigen",
#   build_file = "@//:3rdparty/eigen/eigen.BUILD",
#   urls = ["https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.zip"],
#   strip_prefix = "eigen-3.4.0",
#   sha256 = "1ccaabbfe870f60af3d6a519c53e09f3dcf630207321dffa553564a8e75c4fc8",
# )