#include <iostream>
#include <cmath>
#include <numeric>
#include "/home/aditya/eigen/Eigen/Dense"
#include "GaussianDistribution.hpp"

class GMMDistribution
{
    public:
        double_t weight_sum_tol = 1e-4;
        GMMDistribution(const std::vector<Eigen::RowVectorXd>& means, const std::vector<Eigen::MatrixXd>& cov_matrices, const std::vector<double_t>& weights)
        {
            mu_vector = means;
            Sigma_vector = cov_matrices;
            w_vector = weights;
        }
        double_t probability(Eigen::RowVectorXd X) //https://en.wikipedia.org/wiki/Multivariate_normal_distribution#Density_function
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

    private:
        std::vector<Eigen::RowVectorXd> mu_vector;
        std::vector<Eigen::MatrixXd> Sigma_vector;
        std::vector<double_t> w_vector;

        bool size_check = (mu_vector.size() == Sigma_vector.size() && mu_vector.size() == w_vector.size());
        bool weight_sum_check = (std::abs(std::accumulate(w_vector.begin(), w_vector.end(), 0.0) - 1.0) <= weight_sum_tol);

        std::string size_check_error_msg()
        {
            if (!size_check)
                std::cout << "Error: The number of means, covariance matrices and weights is not the same!";
        }
        std::string weight_sum_error_msg()
        {
            if (!weight_sum_check)
                std::cout << "Error: The sum of the weights is not close to 1 (with tolerance of " << std::to_string(weight_sum_tol) << ").";
        }

};