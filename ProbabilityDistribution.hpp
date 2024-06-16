#ifndef PROBABILITY_DISTRIBUTION_HPP
#define PROBABILITY_DISTRIBUTION_HPP

#include <cstddef>
#include <iostream>
#include <cmath>
#include "Eigen/Dense"

template<std::size_t dim>
class ProbabilityDistribution
{
    public:
        /// p(X)
        virtual double_t probability(const Eigen::Vector<double_t, dim>& X) = 0;
};

#endif