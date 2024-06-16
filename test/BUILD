cc_test(
    name = "Filtering_test",
    # srcs = ["test_GaussianDistribution.cpp",
    #         "test_GaussianSampler.cpp",
    #         "test_GMMDistribution.cpp"],
    srcs = glob(["*.cpp"]),
    deps = ["@eigen",
    "//src:Filtering",
    "@com_google_googletest//:gtest_main"],
    visibility = ["//visibility:public"],
)
