#include <gtest/gtest.h>
#include "GaussianDistribution.hpp"

TEST(test_GaussianDistribution, testGaussianDistProbability)
{
    Eigen::Vector3d mu{0,0,0};
    Eigen::Matrix3d Sigma{{1,0,0},
            {0,1,0},
            {0,0,1}};
    GaussianDistribution G1(mu, Sigma);
    Eigen::Vector3d X{1, 1, 1};
    double_t p_of_X = G1.probability(X);
    EXPECT_GT(p_of_X, 0);
    EXPECT_LT(p_of_X, 1);
    Eigen::Vector3d X2{2, 2, 2};
    EXPECT_LT(G1.probability(X2), p_of_X);
}
