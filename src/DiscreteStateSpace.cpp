#include "DiscreteStateSpace.hpp"

/* Return vector X is the set of state from X_1 to X_{n+1} for given IC X_0 and series of inputs U_0, U_1, ..., U_n
Therefore, in the definition below, X[idx] for a given idx refers to X_{k+1},
but U[idx] refers to U_k.*/
std::vector<Eigen::VectorXd> DiscreteStateSpace::propagate_n_steps(const Eigen::VectorXd& X0, const std::vector<Eigen::VectorXd>& U)
{
    std::vector<Eigen::VectorXd> X(U.size(), X0);
    for (size_t idx = 0; idx<X.size(); ++idx)
    {
        if (idx == 0)
        {
            X[idx] = Ad*X0 + Bd*U[0];
        }
        else
        {
            X[idx] = Ad*(X[idx-1]) + Bd*U[idx];
        }
    }

    // // Alternative version - have to check which one's faster and/or less memory intensive
    // std::vector<Eigen::VectorXd> X;
    // X.reserve(U.size());
    // for (const auto& U_k : U)
    // {
    //     if (U_k == U.front())
    //     {
    //         X.emplace_back(Ad*X0 + Bd*U_k);
    //     }
    //     else
    //     {
    //         X.emplace_back(Ad*(X.back()) + Bd*U_k);
    //     }
    // }
    return X;
}
