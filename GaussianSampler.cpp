#include "GaussianSampler.hpp"

/* This needs to be completely re-worked. The number of z values to be genrated is not the sample size,
but the dimension of the Gaussian distribution. Therefore, z is a column vector of the same size as G_.mu.
Since L is a matrix of the same dimensions as G_.Sigma, one individual sample is generated as G_.mu + L*z.
This needs to be repeated n_samples_ times, preferably using a std::transform()*/
std::vector<Eigen::VectorXd> GaussianSampler::generate_samples()
{
    std::vector<Eigen::VectorXd> return_vec(n_samples_, G_.mu);
    // std::generate(return_vec.begin(), return_vec.end(), &GaussianSampler::generate_z);
    std::generate(return_vec.begin(), return_vec.end(), [&] () {return generate_z();});
    std::transform(return_vec.begin(), return_vec.end(), return_vec.begin(),
                    [&] (Eigen::VectorXd z) {return G_.mu + L*z;});

    return return_vec;
}

double_t GaussianSampler::gen_std_normal_dist(uint64_t seed_in)
{
    std::default_random_engine generator{seed_in};
    // std::normal_distribution<double_t> std_normal_dist(0.0, 1.0); -> This is apparently invalid for initialiazing non-static class members.
    // See https://stackoverflow.com/a/32155815/10353367
    std::normal_distribution<double_t> std_normal_dist{0.0, 1.0};
    double_t rand_num = std_normal_dist(generator);
    return rand_num;
}

Eigen::VectorXd GaussianSampler::generate_z()
{
    Eigen::VectorXd z_vector{G_.mu}; // Init with G_.mu just to get same size
    std::vector<uint_least64_t> seeds(G_.mu.size(), 0);
    std::generate(seeds.begin(), seeds.end(), rand); // First fill with uniform rand to use as seeds
    // Then sample from std. normal distribution using those seeds
    std::transform(seeds.begin(), seeds.end(), z_vector.begin(), &GaussianSampler::gen_std_normal_dist);
    return z_vector;
}