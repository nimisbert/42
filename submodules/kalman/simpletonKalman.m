clear;clc;
pkg load statistics;

# ---
function g = simpleton_kalman_gain(Eest, Emea)
  g = Eest / (Eest + Emea);
end
function cEST = simpleton_kalman_estimate(EST, KG, MEA)
  cEST = EST + KG * (MEA - EST);
end
function cEest = simpleton_kalman_error_estimate(Emea, Eest)
  cEest = (Emea*Eest) / (Emea + Eest);
end

function [estimate, error_in_estimate] = simpleton_kalman(EST, Eest, MEA, Emea)
  N = max(size(MEA))
  dEst = EST;
  estimate = dEst;
  for i = 1:N
    g = simpleton_kalman_gain(Eest, Emea)
    dEst = simpleton_kalman_estimate(dEst, g, MEA(i));
    Eest = simpleton_kalman_error_estimate(Emea, Eest);
    estimate = [estimate,dEst];
  endfor
end

# --- Params --- #
N = 200;
tmax = 2;
step = tmax/N;

# --- Datas --- #
d = normrnd(4,0.6,200,1);
t = 0:step:tmax-step;

# --- Kalman --- #
estimates = simpleton_kalman(5, 1, d, 0.1)

# --- Plot --- #
plot(t,d, "b.", t, estimates(1:200), "r-");
