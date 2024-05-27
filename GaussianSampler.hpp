#include <iostream>
#include <cmath>
#include <numeric>
#include <random>
#include <vector>
#include "Eigen/Dense"
#include "Eigen/Cholesky"
#include "GaussianDistribution.hpp"

class GaussianSampler
{
    public:
        GaussianSampler(const GaussianDistribution& GD, const uint_least64_t& n, const uint_least64_t& s) : G_{GD}, n_samples_{n}, seed_{s}
        {}
        std::vector<Eigen::VectorXd> generate_samples();

    private:
        GaussianDistribution G_;
        uint_least64_t n_samples_;
        uint_least64_t seed_;
        Eigen::MatrixXd L {G_.Sigma.llt().matrixL()}; // Cholesky Decomp factor

        static double_t gen_std_normal_dist(uint64_t seed_in);

        Eigen::VectorXd generate_z();
};