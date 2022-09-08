clc;
clear;
#INCLUDES
pkg load signal

#SPECS
#FILTER
Fs = 40e3;  %Sampling frequency
F0 = 5e3;   %Filter frequency

r  = 0.95;
N  = 10000; %Number of samples

p = r*exp(-j*2*pi*[-F0 F0]/Fs); %poles : denominator
z =   exp(-j*2*pi*[-F0 F0]/Fs); %zeros : numerator

a = poly(p);
b = poly(z);
[H,F] = freqz(b,a,N,Fs); #complex response frequency

%Signals
tmax = 0.005;
f0 = F0;
f1 = F0/2;
f2 = 2*F0;
N  = tmax*Fs;
t  = [0:N-1]*tmax/N;

x0 = 2*cos(2*pi*f0*t);
x1 = 2*cos(2*pi*f1*t);
x2 = 2*cos(2*pi*f2*t + pi/4);
x3 = x0+x1+x2;

x4 = filter(b,a,x3); %Apply filter to x3 signal

#PLOT
r = 2; c = 2;
#
subplot(r,c,1);
zplane([z,p]);
title("Filter poles and zeros");

subplot(r,c,2);
plot(F,20*log10(abs(H)));
title("Filter frequency response");
ylabel("|H(f)| (dB)");
xlabel("f (Hz)");

subplot(r,c,3);
plot(t,x3);
title("Signal to filter");
ylabel("Amplitude s.u.");
xlabel("time [s]");

subplot(r,c,4);
plot(t,x4);
title("Filtered frequency");
ylabel("Amplitude s.u.");
xlabel("time [s]");
