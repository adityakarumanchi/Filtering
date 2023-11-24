import numpy as np
import scipy as sc
from scipy.stats import multivariate_normal as sc_mult_Gauss
from matplotlib import pyplot as plt

# mu = np.array([0, 0, 0])
# cov = np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
# ensemble = np.random.multivariate_normal(mu, 0.010 * cov, 1000)
# ens_prob = sc_mult_Gauss.pdf(ensemble, mean=mu, cov=cov)

# fig, ax = plt.subplots(1, 1)
# plt.hist(ens_prob)
# plt.show()


def kalman_filter(
    A: np.array,
    B: np.array,
    C: np.array,
    Q: np.array,
    R: np.array,
    u: np.array,
    curr_state_estim: np.array,
    curr_cov_estim: np.array,
    curr_meas: np.array,
):
    predicted_state = A.dot(curr_state_estim) + B.dot(u)
    predicted_cov = np.matmul(np.matmul(A, curr_cov_estim), np.transpose(A)) + Q
    residual = curr_meas - C.dot(predicted_state)
    # gain = (
    #     predicted_cov
    #     * np.transpose(C)
    #     * np.linalg.inv(C * predicted_cov * np.transpose(C) + R)
    # )
    gain = np.matmul(
        np.matmul(predicted_cov, np.transpose(C)),
        np.linalg.inv(np.matmul(np.matmul(C, predicted_cov), np.transpose(C)) + R),
    )
    updated_state = predicted_state + np.matmul(gain, residual)
    updated_cov = np.matmul(
        np.identity(np.size(predicted_cov)[0]) - np.matmul(gain, C), predicted_cov
    )


A = np.array([[-2, -5], [2, -3]]) * 2
B = np.array([0, -1])
C = np.identity(2)
dt = 0.01
Ad = np.identity(2) + A * dt
# print(Ad)
Bd = B * dt

t_steps = np.arange(0, 5, dt)
X = np.zeros(shape=(np.size(t_steps), 2))
X[0, :] = X[0, :] + 5
# print(X[0, :])
U = 0
for i in range(np.size(t_steps) - 1):
    # print(i, Ad.dot(X[i, :]))
    X[i + 1, :] = Ad.dot(X[i, :])  # + Bd * U

fig, ax = plt.subplots(2, 1)
ax[0].plot(t_steps, X[:, 0])
ax[1].plot(t_steps, X[:, 1])

plt.show()
