#include <iostream>
#include <cmath>
#include "/home/aditya/eigen/Eigen/Dense"

class GaussianDistribution
{
    public:
        Eigen::VectorXd mu;
        Eigen::MatrixXd Sigma;
        GaussianDistribution(const Eigen::VectorXd& m, const Eigen::MatrixXd& C) : mu{m}, Sigma{C} {}

        double_t probability(Eigen::VectorXd X) //https://en.wikipedia.org/wiki/Multivariate_normal_distribution#Density_function
        {
            double_t exponent = -0.5*(mu-X).transpose()*(Sigma.inverse())*(mu-X);
            double_t p_of_x_ = pow(2*M_PI, -X.size()/2.0) * pow(Sigma.determinant(), -0.5) * std::exp(exponent);

            return p_of_x_;
        };

    // private:
    //     // To-do: check that Sigma is positive-definite and use it as condition for calculating probability.
};