#include <iostream>
#include <cmath>
#include <numeric>
#include "/home/aditya/eigen/Eigen/Dense"
#include "GMMDistribution.hpp"

class GMMSampler
{
    public:
        GMMSampler() {}
        std::vector<Eigen::VectorXd> generate_samples (GMMDistribution& G)
        {
            auto cumul_weights = G.w_vector;
            std::partial_sum(G.w_vector.begin(), G.w_vector.end(), cumul_weights.begin());

            

        }

    private:
        uint_least64_t n_samples;
        uint_least64_t seed;

};
