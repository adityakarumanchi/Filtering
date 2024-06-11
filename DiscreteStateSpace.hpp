#include "Eigen/Dense"
#include <Eigen/src/Core/Matrix.h>

class DiscreteStateSpace
{
    public:
        DiscreteStateSpace(const Eigen::MatrixXd& _Ad, const Eigen::MatrixXd& _Bd, const Eigen::MatrixXd& _Cd, const Eigen::MatrixXd& _Dd)
            : Ad{_Ad}, Bd{_Bd}, Cd{_Cd}, Dd{_Dd} {}
    
    void propagate_n_steps(std::vector<Eigen::VectorXd>& X, const std::vector<Eigen::VectorXd>& U)
    {
        if (X.size() == U.size())
        {
            for (size_t idx = 1; idx<X.size(); ++idx)
            {
                X[idx] = Ad*(X[idx-1]) + Bd*U[idx-1];
            }
        }
    }
    
    private:
        Eigen::MatrixXd Ad;
        Eigen::MatrixXd Bd;
        Eigen::MatrixXd Cd;
        Eigen::MatrixXd Dd;
};