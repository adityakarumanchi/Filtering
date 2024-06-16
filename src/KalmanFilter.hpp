#ifndef KALMAN_FILTER_HPP
#define KALMAN_FILTER_HPP

#include "Eigen/Dense"
// #include <Eigen/src/Core/Matrix.h>

// Template for dims probably not required?
// template<int dim_state, int dim_obs>
class KalmanFilter
{
    public:
        KalmanFilter(const Eigen::MatrixXd& _A, const Eigen::MatrixXd& _B, const Eigen::MatrixXd& _C, const Eigen::MatrixXd& _D,
        const Eigen::MatrixXd& _Q, const Eigen::MatrixXd& _R) : A{_A}, B{_B}, C{_C}, D{_D}, Q{_Q}, R{_R} {}
        // Templated versions are probably not required?
        // Eigen::Matrix<double, dim_state, dim_state> Q;
        // Eigen::Matrix<double, dim_obs, dim_obs> R;

        Eigen::MatrixXd A; // State Transition Matrix
        Eigen::MatrixXd B; // Control Input coef. matrix
        Eigen::MatrixXd C; // Observation matrix
        Eigen::MatrixXd D; // Control pass-through
        Eigen::MatrixXd Q; // Process covariance
        Eigen::MatrixXd R; // Observation covariance

        Eigen::VectorXd X_kk;
        Eigen::VectorXd X_k_prev;
        Eigen::VectorXd Y_k;
};

#endif // KALMAN_FILTER_HPP