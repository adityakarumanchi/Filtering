# load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")

# buildifier(
#     name = "buildifier",
# )

cc_library(
    name = "Filtering",
    srcs = ["GaussianDistribution.cpp",
            "GMMDistribution.cpp",
            "GaussianSampler.cpp"],
    hdrs = ["GaussianDistribution.hpp",
            "GMMDistribution.hpp",
            "GaussianSampler.hpp"],
    deps = [":eigen"]
)

# cc_library(
#     name = "Filtering",
#     srcs = ["mylib.cc"],
#     hdrs = ["mylib.h"],
#     deps = [":lower-level-lib"]
# )
cc_test(
    name = "Filtering_test",
    srcs = ["test_GaussianDistribution.cpp",
            "test_GaussianSampler.cpp",
            "test_GMMDistribution.cpp"],
    deps = [":eigen"]
)
