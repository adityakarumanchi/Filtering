#include <gtest/gtest.h>
#include "GMMDistribution.hpp"

TEST(test_GMMDistribution, testGMMDistProbability)
{
    const std::vector<Eigen::RowVector3d> mu_vec{{0,0,0}, {1,1,1}, {-1,-1,-1}};
    const std::vector<Eigen::Matrix3d> Sigma_vec{
        Eigen::Matrix<double, 3, 3>::Identity(),
        0.5*Eigen::Matrix<double, 3, 3>::Identity(),
        0.5*Eigen::Matrix<double, 3, 3>::Identity()};
    const std::vector<double_t> weights{0.5,0.25,0.25};
    GMMDistribution<3> G1{mu_vec, Sigma_vec, weights};
    Eigen::Vector3d X{0.5, 0.75, 0.5};
    double_t p_of_X = G1.probability(X);
    std::cout << "p(X) = " << p_of_X << std::endl;
    EXPECT_GT(p_of_X, 0);
    EXPECT_LT(p_of_X, 1);
    Eigen::Vector3d X2{2, 2, 2};
    double_t p_of_X2 = G1.probability(X2);
    std::cout << "p(X_2) = " << p_of_X2 << std::endl;
    EXPECT_LT(p_of_X2, p_of_X);
}
