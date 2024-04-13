#ifndef GMMDISTRIBUTION_TPP
#define GMMDISTRIBUTION_TPP

#include "GMMDistribution.hpp"

template<std::size_t dim>
double_t GMMDistribution<dim>::probability(const Eigen::Vector<double_t, dim>& X)
{
    double p_of_x_ = 0;

    for (auto idx=0; idx<w_vector.size(); idx++)
    {
        GaussianDistribution GMMComp(mu_vector[idx], Sigma_vector[idx]);
        p_of_x_ += w_vector[idx] * GMMComp.probability(X);
    }

    return p_of_x_;
}

// template<std::size_t dim>
// void GMMDistribution<dim>::size_check_error_msg()
// {
//     if (!size_check)
//         std::cout << "Error: The number of means, covariance matrices and weights is not the same!";
// }
// template<std::size_t dim>
// void GMMDistribution<dim>::weight_sum_error_msg()
// {
//     if (!weight_sum_check)
//         std::cout << "Error: The sum of the weights is not close to 1 (with tolerance of " << std::to_string(weight_sum_tol) << ").";
// }
#endif