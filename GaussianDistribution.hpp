#include <iostream>
#include <cmath>
#include "/home/aditya/eigen/Eigen/Dense"

class GaussianDistribution
{
    public:
        GaussianDistribution(const Eigen::RowVectorXd& mean, const Eigen::MatrixXd& covariance)
        {
            mu = mean;
            Sigma = covariance;
        }
        double_t probability(Eigen::RowVectorXd X) //https://en.wikipedia.org/wiki/Multivariate_normal_distribution#Density_function
        {
            double_t exponent = -0.5*(mu-X)*(Sigma.inverse())*(mu-X).transpose();
            double_t p_of_x_ = pow(2*M_PI, -X.size()/2.0) * pow(Sigma.determinant(), -0.5) * std::exp(exponent);

            return p_of_x_;
        };

    private:
        Eigen::RowVectorXd mu;
        Eigen::MatrixXd Sigma;
        // To-do: check that Sigma is positive-definite and use it as condition for calculating probability.
};