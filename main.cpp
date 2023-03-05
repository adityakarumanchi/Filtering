#include <iostream>
// #include <eigen3/Eigen/Dense>
#include "/home/aditya/eigen/Eigen/Dense"
#include <vector>
#include <numeric>
// #include "GaussianDistribution.hpp"
#include "GaussianSampler.hpp"

struct Params
{
    float C_alpha_f = 4.5e4;
    float C_alpha_r = 4.5e4;
    float mass = 2000;
    float Iz = 4000;
    float lf = 1.3;
    float lr = 1.5;
};

void bicycle_dist_nl_discrete(Eigen::Vector4d& X, const float U, const float dxpos, const Params& VehParams, const float Vx)
{
    float Cf = VehParams.C_alpha_f;
    float Cr = VehParams.C_alpha_r;
    float lf = VehParams.lf;
    float lr = VehParams.lr;
    float m  = VehParams.mass;
    float Iz = VehParams.Iz;

    double beta  = X(1);
    double gamma = X(2);
    double psi   = X(3);
    double K     = 1/(Vx*cos(psi + gamma));

    double a1 = (Cr*lr - Cf*lf)/Iz;
    double a2 = -(Cr*pow(lr,2) + Cf*pow(lf,2))/(Iz*Vx);
    double a3 = Cf*lf/Iz;
    double a4 = -(Cf + Cr)/(m*Vx);
    double a5 = -1 + (Cr*lr - Cf*lf)/(m*pow(Vx,2));
    double a6 = Cf/(m*Vx);

    Eigen::Vector4d dxdt(K*(a4*beta + a5*gamma + a6*U),
    K*(a1*beta + a2*gamma + a3*U),
    K*beta,
    tan(gamma + psi));

    X += dxpos*dxdt;
}

// void GMMSampling(std::vector<double>& Weights)
// {
//     std::vector<double> CumulWeights(Weights.size(), 0);
// //    CumulWeights = Weights;
//     std::partial_sum(Weights.begin(), Weights.end(), CumulWeights.begin());
//     for (auto elem : CumulWeights)
//         std::cout<<elem<<" ";
// }

int main()
{
    // Params VehParams;
    // Eigen::Vector4d X(0.01, 0.01, 0.01, 0);
    // std::vector<double> Weights(5, 0.1);
    // GMMSampling(Weights);
    Eigen::Vector3d mu{0,0,0};
    Eigen::Matrix3d Sigma{{1,0,0},
            {0,1,0},
            {0,0,1}};
    GaussianDistribution G1(mu, Sigma);
    Eigen::Vector3d X{1, 1, 1};

    std::cout << G1.probability(X*0.05);
    GaussianSampler GS1(G1, 1e3, 5);
    return 0;
}
