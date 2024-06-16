#ifndef GMMDISTRIBUTION_HPP
#define GMMDISTRIBUTION_HPP

#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
#include "Eigen/Dense"
#include "GaussianDistribution.hpp"

template<std::size_t dim>
class GMMDistribution
{
    public:
        double_t weight_sum_tol = 1e-4;
        GMMDistribution(const std::vector<Eigen::Vector<double_t, dim>>& m,
            const std::vector<Eigen::Matrix<double_t, dim, dim>>& C,
            const std::vector<double_t>& w) : mu_vector{m}, Sigma_vector{C}, w_vector{w} {};

        double_t probability(const Eigen::Vector<double_t, dim>& X)
        {
            double p_of_x_ = 0;
            for (size_t idx=0; idx<w_vector.size(); idx++)
            {
                GaussianDistribution GMMComp(mu_vector[idx], Sigma_vector[idx]);
                p_of_x_ += w_vector[idx] * GMMComp.probability(X);
            }
            return p_of_x_;
        }

        std::vector<Eigen::Vector<double_t, dim>> mu_vector;
        std::vector<Eigen::Matrix<double_t, dim, dim>> Sigma_vector;
        std::vector<double_t> w_vector;
};

#endif // GMMDISTRIBUTION_HPP