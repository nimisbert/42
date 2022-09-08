clc
clear

#Filter
#Specs
Fs = 40e3;
F1 =  5e3; %Filter window lower bound
F2 = 10e3; %Filter window upper bound
Delta1 = 0.5; %dB
Delta2 = -40; %dB

P = 12; %Order
N = 2*P+1;
N2= 12*N;
f = (Fs/N2)*[0:N2-1];
i = [-P:P];
t = (1/Fs)*[-P:P];

%1 : Impulse response
h = ((F1+F2)/Fs)*sinc(i*((F1+F2)/Fs)); %Impulse response
%2 : gabarit
gabarit_superieur = [ Delta1*ones(1,round(N2*F2/Fs)) , Delta2*ones(1,size(f,2)-round(N2*F2/Fs))];
gabarit_inferieur = [-Delta1*ones(1,round(N2*F1/Fs)) ,   -100*ones(1,size(f,2)-round(N2*F1/Fs))];
%3 : Filter
H = fft(h,N2);
w = hanning(N)';
h = h.*w;
G = fft(h,N2);
%4 : Limitting ressources
B = 8;
q = h*((P+1)/((2^B)-1));
h = round(h/q)*q;
E = fft(h,N2);
bin = dec2bin(abs(round(h/q)),B-1);

%Plot
r = 2; c = 2;
%
subplot(r,c,1);
plot(t,h,'-o');

subplot(r,c,2);
hold on;
plot(f,gabarit_inferieur,'r-');
plot(f,gabarit_superieur,'r-');
title("Frequency response");
xlabel("Frequency (Hz)");
ylabel("|H(z)| [dB]");
grid on;

subplot(r,c,3);
hold on;
plot(f,20*log10(abs(H)),'b');
plot(f,20*log10(abs(G)),'g');
plot(f,20*log10(abs(E)),'c');
