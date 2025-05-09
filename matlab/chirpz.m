
%   时间2025 05 07
clc     ;
clear   ; 
close   ;


%%

clc;clear;close all;
N = 100000;
f1 = 100;
f2 = 101;
fs = 8000;
Ts = 1/fs; 
ts = (1:N)*Ts;
x = exp(1i * 2*pi*f1*ts) + cos(2*pi*f2*ts) ; 
% y_DFT = abs(fft(x)); %%DFT

m = 20000000;
w = exp(-1i*2*pi*(150-50)/(m*fs));
a = exp(1i*2*pi*50/fs);

tic
y_CZT = abs(czt(x,m,w,a));%%CZT
toc

% fn = (0:N-1)/N;
% fy = fs*fn;
% fz = (150-50)*fn + 50;
% fyy = fs*(0:2*N-1)/(2*N);
% xx = [x zeros(1,N)];
% yy_DFT = abs(fft(xx)); %%插0 DFT
% plot(yy_DFT);
% plot(fy,20*log10(y_DFT), fz,20*log10(y_CZT), fyy,20*log10(yy_DFT));
% xlim([80 120]);
% legend('DFT','CZT','插0 DFT');
