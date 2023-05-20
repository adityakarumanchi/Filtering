#include <gtest/gtest.h>
#include "GaussianSampler.hpp"

TEST(test_GaussianSampler, testGaussianSamplProbability)
{
    Eigen::Vector3d mu{0,0,0};
    Eigen::Matrix3d Sigma{{1,0,0},
            {0,1,0},
            {0,0,1}};
    GaussianDistribution G(mu, Sigma);
    GaussianSampler GS(G, 100, 0);
    auto ens = GS.generate_samples();
    for (const auto& v : ens)
    {
      EXPECT_GT(G.probability(v), 0);
      EXPECT_LT(G.probability(v), 1);
    }
}
