# load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")

# buildifier(
#     name = "buildifier",
# )

cc_library(
    name = "Filtering",
    # srcs = ["GaussianDistribution.cpp",
    #         "GaussianSampler.cpp"],
    # hdrs = ["GaussianDistribution.hpp",
    #         "GMMDistribution.hpp",
    #         "GaussianSampler.hpp"],
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = ["@eigen"],
    visibility = ["//visibility:public"],
)