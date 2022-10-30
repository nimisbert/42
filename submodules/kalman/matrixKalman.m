clear;clc;

# Notations: 
# P = process covariance matrix
# R = Sensor noise covariance matrix
# K = kalman gain
# I = identity matrix
# Y = measurement of the state
# Q = Process noise covariance matrix
# w = predicted state noise matrix
# u = control variable matrix
# k = numering of the sample

# --- STATE MATRIX --- #

# X = state matrix
# e.g. : X = [ x, x' ]
#      : X = [ x, x', y, y', z, z' ]
#      : X = [ x, y, z, x', y', z' ]
#      : ....
# u = control variable matrix
# w = noise in the process
