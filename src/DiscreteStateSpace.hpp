#ifndef DISCRETE_STATE_SPACE_HPP
#define DISCRETE_STATE_SPACE_HPP

#include <vector>
#include "Eigen/Dense"

class DiscreteStateSpace
{
    public:
        DiscreteStateSpace(const Eigen::MatrixXd& _Ad, const Eigen::MatrixXd& _Bd, const Eigen::MatrixXd& _Cd, const Eigen::MatrixXd& _Dd)
            : Ad{_Ad}, Bd{_Bd}, Cd{_Cd}, Dd{_Dd} {}
    
    /// @param X0 is the initial condition
    /// @param U is the series of input.
    /// @brief For state-space propagation with an initial condition X0 and series of inputs. The output vector has the same size as U.
    std::vector<Eigen::VectorXd> propagate_n_steps(const Eigen::VectorXd& X0, const std::vector<Eigen::VectorXd>& U);

    private:
        Eigen::MatrixXd Ad;
        Eigen::MatrixXd Bd;
        Eigen::MatrixXd Cd;
        Eigen::MatrixXd Dd;
};

#endif // DISCRETE_STATE_SPACE_HPP