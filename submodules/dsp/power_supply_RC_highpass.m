clear;
clc;
pkg load signal;

% Source Signal 
fe = 4e3;   % sampling frequency because digital simulation
f1 = 50;    % 50 Hz 
T1 = 1/f1;  % 0.02s
f2 = 2e3;   % some noise signal
V = 12;     % voltage output of transformer

Tmax = 10*T1;

t = 0:T1/fe:Tmax;
v = V*sin(2*pi*f1*t) + (V*0.01)*sin(2*pi*f2*t); % transformer output
r = abs(v); % rectifier output

% Filter 
C = 470e-6;        % because I already have a bunch of them
fc = 50*0.05;      % lower than desired cutoff for stability
R = 1/(2*pi*C*fc); % resistor value I'm looking for

a0  = 1;           % no amplifier
tau = R*C;         % time constant

s = tf(a0, [tau 1]); % 1st order RC low pass filter
y = lsim(s, r, t);   % simulate output based on rectifier signal as input

plot(t,v,'b',t,r,'r',t,y,'g');
title("RC low pass filter for power supply electronics project");
xlabel("time [s]");
ylabel("voltage [V]");
legend("Transformer output","Rectifier output","RC lowpass output");