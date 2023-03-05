#include <iostream>
#include <cmath>
#include <numeric>
#include "/home/aditya/eigen/Eigen/Dense"
#include "/home/aditya/eigen/Eigen/Cholesky"
#include "GaussianDistribution.hpp"

class GaussianSampler
{
    public:
        GaussianSampler(const GaussianDistribution& GD, const uint_least64_t& n, const uint_least64_t& s) : G{GD}, n_samples{n}, seed{s}
        {}


        // std::vector<Eigen::VectorXd> generate_samples()
        // {

        // }

        private:
            uint_least64_t n_samples;
            uint_least64_t seed;
            GaussianDistribution G;
};