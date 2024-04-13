#ifndef GAUSSIAN_DISTRIBUTION_HPP
#define GAUSSIAN_DISTRIBUTION_HPP

#include <iostream>
#include <cmath>
#include "/home/aditya/eigen/Eigen/Dense"

class GaussianDistribution
{
    public:
        Eigen::VectorXd mu; /// Mean
        Eigen::MatrixXd Sigma; /// Covariance
        /// Constructor
        GaussianDistribution(const Eigen::VectorXd& m, const Eigen::MatrixXd& C) : mu{m}, Sigma{C} {};
        /// p(X)
        double_t probability(const Eigen::VectorXd& X); //https://en.wikipedia.org/wiki/Multivariate_normal_distribution#Density_function

    // private:
    //     // To-do: check that Sigma is positive-definite and use it as condition for calculating probability.
};

#endif
