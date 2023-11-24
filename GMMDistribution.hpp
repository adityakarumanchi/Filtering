#include <iostream>
#include <cmath>
#include <numeric>
#include "/home/aditya/eigen/Eigen/Dense"
#include "GaussianDistribution.hpp"

template<std::size_t dim>
class GMMDistribution
{
    public:
        double_t weight_sum_tol = 1e-4;
        GMMDistribution(const std::vector<Eigen::RowVector<double_t, dim>>& m,
            const std::vector<Eigen::Matrix<double_t, dim, dim>>& C,
            const std::vector<double_t>& w) :
        mu_vector{m}, Sigma_vector{C}, w_vector{w} {}

        double_t probability(Eigen::RowVector<double, dim> X)
        {
            double p_of_x_ = 0;
            if (size_check && weight_sum_check)
            {
                for (auto idx=0; idx<w_vector.size(); idx++)
                {
                    GaussianDistribution GMMComp(mu_vector[idx], Sigma_vector[idx]);
                    p_of_x_ += w_vector[idx] * GMMComp.probability(X);
                }
            }

            return p_of_x_;
        };

        std::vector<Eigen::RowVector<double_t, dim>> mu_vector;
        std::vector<Eigen::Matrix<double_t, dim, dim>> Sigma_vector;
        std::vector<double_t> w_vector;
        // Eigen::RowVector<double_t, dim> mu_vector[num_comp];
        // Eigen::Matrix<double_t, dim, dim> Sigma_vector[num_comp];
        // double_t w_vector[num_comp];

    // private:
        bool size_check = (mu_vector.size() == Sigma_vector.size() && mu_vector.size() == w_vector.size());
        bool weight_sum_check = (std::abs(std::accumulate(w_vector.begin(), w_vector.end(), 0.0) - 1.0) <= weight_sum_tol);

        void size_check_error_msg()
        {
            if (!size_check)
                std::cout << "Error: The number of means, covariance matrices and weights is not the same!";
        }
        void weight_sum_error_msg()
        {
            if (!weight_sum_check)
                std::cout << "Error: The sum of the weights is not close to 1 (with tolerance of " << std::to_string(weight_sum_tol) << ").";
        }
};