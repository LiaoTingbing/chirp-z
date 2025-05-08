
#include "../include/czt.h"

//	单列实数czt变换
cx_vec czt(const vec& x, const uword M, const cx_double W, const cx_double A)
{
	//	采样数量
	uword N = x.n_rows;
	//	计算最小2的幂次方
	uword m = ceil(log2(N + M - 1));
	uword L = pow(2, m);

	//	计算h(n)序列
	cx_vec h(L, fill::zeros);
	h.rows(0, M - 1) = pow(W * ones(M), -0.5 * pow(linspace(0, M - 1, M), 2));
	h.rows(L - N + 1, L - 1) = pow(W * ones(N - 1), -0.5 * pow(linspace(L-N+1, L-1, N-1) - L, 2));
	//	计算h(n)序列的L点dft变换
	cx_vec H = fft(h, L);

	//	对x(n)加权、补零，并计算DFT；
	cx_vec g(L, fill::zeros);
	g.rows(0, N - 1) = x % pow(A * ones(N), -linspace(0, N - 1, N))
		% pow(W * ones(N), 0.5 * pow(linspace(0, N - 1, N), 2));
	cx_vec G = fft(g, L);

	//	计算Y = GH
	cx_vec Y = G % H;
	cx_vec y = ifft(Y, L);

	//	计算变换点
	cx_vec X = pow(W * ones(M), 0.5 * pow(linspace(0, M - 1, M), 2)) % y.rows(0, M - 1);

	return X;
}

//	单列复数czt变换
cx_vec czt(const cx_vec& x, const uword M, const cx_double W, const cx_double A)
{
	//	采样数量
	uword N = x.n_rows;
	//	计算最小2的幂次方
	uword m = ceil(log2(N + M - 1));
	uword L = pow(2, m);

	//	计算h(n)序列
	cx_vec h(L, fill::zeros);
	h.rows(0, M - 1) = pow(W * ones(M), -0.5 * pow(linspace(0, M - 1, M), 2));
	h.rows(L - N + 1, L - 1) = pow(W * ones(N - 1), -0.5 * pow(linspace(L - N + 1, L - 1, N - 1) - L, 2));
	//	计算h(n)序列的L点dft变换
	cx_vec H = fft(h, L);

	//	对x(n)加权、补零，并计算DFT；
	cx_vec g(L, fill::zeros);
	g.rows(0, N - 1) = x % pow(A * ones(N), -linspace(0, N - 1, N))
		% pow(W * ones(N), 0.5 * pow(linspace(0, N - 1, N), 2));
	cx_vec G = fft(g, L);

	//	计算Y = GH
	cx_vec Y = G % H;
	cx_vec y = ifft(Y, L);

	//	计算变换点
	cx_vec X = pow(W * ones(M), 0.5 * pow(linspace(0, M - 1, M), 2)) % y.rows(0, M - 1);

	return X;
}

