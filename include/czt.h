

#pragma once 
#define ARMA_USE_FFTW3
#include <armadillo>
//#include <omp.h>
using namespace arma;


//  x是输入信号列量
//  m转换的频率点数
//  w等分相位角度
//  a初始位置
//  \sum_n^{N-1} x_n (aw^{0:m-1})^{-n}
template<class T>
auto czt( T& x, const uword M, const cx_double W, const cx_double A);

template<class T>
auto  czt(T& x, const uword M, const cx_double W, const cx_double A)
{
	//	采样数量
	//auto s = ;
	uword N = size(x).n_rows;
	//x.n_rows;
	//	计算最小2的幂次方
	uword m = ceil(log2(N + M - 1));
	uword L = pow(2, m);

	//	计算h(n)序列
	cx_vec h(L, fill::zeros);
	h.rows(0, M - 1) = pow(cx_vec(M,fill::value(W)), -0.5 * pow(linspace(0, M - 1, M), 2));
	h.rows(L - N + 1, L - 1) = pow(cx_vec(N - 1,fill::value(W)), -0.5 * pow(linspace(L - N + 1, L - 1, N - 1) - L, 2));
	//	计算h(n)序列的L点dft变换
	cx_vec H = fft(h, L);

	//	对x(n)加权、补零，并计算DFT；
	cx_vec g(L, fill::zeros);
	g.rows(0, N - 1) = x % pow(cx_vec(N,fill::value(A)), -linspace(0, N - 1, N))
		% pow(cx_vec(N,fill::value(W)), 0.5 * pow(linspace(0, N - 1, N), 2));
	cx_vec G = fft(g, L);

	//	计算Y = GH
	cx_vec Y = G % H;
	cx_vec y = ifft(Y, L);

	//	计算变换点
	cx_vec X = pow(cx_vec(M,fill::value(W)), 0.5 * pow(linspace(0, M - 1, M), 2)) % y.rows(0, M - 1);
 
	return X;
}
