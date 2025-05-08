

#pragma once 
#define ARMA_USE_FFTW3
#include <armadillo>

using namespace arma;


//  x是输入信号列量
//  m转换的频率点数
//  w等分相位角度
//  a初始位置
//  \sum_n^{N-1} x_n (aw^{0:m-1})^{-n}
cx_vec czt(const vec& x, const uword M, const cx_double W, const cx_double A);


cx_vec czt(const cx_vec& x, const uword M, const cx_double W, const cx_double A);

