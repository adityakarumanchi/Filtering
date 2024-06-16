#include <gtest/gtest.h>
#include "src/GaussianSampler.hpp"

TEST(test_GaussianSampler, testGaussianSamplProbability)
{
    Eigen::Vector3d mu{0,0,0};
    Eigen::Matrix3d Sigma{{1,0,0},
            {0,1,0},
            {0,0,1}};
    uint_least64_t n_samples{10000};
    GaussianDistribution G(mu, 0.01*Sigma);
    GaussianSampler GS(G, n_samples, 552);
    auto ens = GS.generate_samples();
    std::vector<double_t> ens_prob(ens.size(), 0);
    std::transform(ens.begin(), ens.end(), ens_prob.begin(),
    [&] (Eigen::VectorXd in_vec) {return G.probability(in_vec);});
    for (const auto& p : ens_prob)
    {
      EXPECT_GT(p, 0);
      EXPECT_LT(p, 1);
    }

    // Checking the nature of the distribution
    std::sort(ens_prob.begin(), ens_prob.end());
    uint8_t n_bins = 15;
    std::vector<uint_least64_t> counts(n_bins, 0);
    std::cout << "ens_prob.front(): " << ens_prob.front() << ", ens_prob.back(): " << ens_prob.back() << std::endl;
    for (uint8_t i=1; i<n_bins; i++)
    {
      auto bin_ulim_iter = std::find_if(ens_prob.begin(), ens_prob.end(), 
                    [&](double_t val) {return val>=ens_prob.back()*i/n_bins;});
      auto bin_llim_iter = std::find_if(ens_prob.begin(), ens_prob.end(), 
                    [&](double_t val) {return val>=ens_prob.back()*(i-1)/n_bins;});
      counts[i-1] = bin_ulim_iter - bin_llim_iter;
    }
    counts.back() = n_samples - std::accumulate(counts.begin(), counts.end(), 0);

    // for (auto& count : counts)
    // {
    //   std::cout << "Bin count: " << count << std::endl;
    // }
}
