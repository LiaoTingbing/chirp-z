
# Chirp Z 变换

由于Armadillo没有czt变换函数，就用armadillo写了个czt变换的函数。

## 原理

[ChirpZ原理](https://blog.csdn.net/weixin_44625313/article/details/129127826)
[数学推导](<document/Martin - 2005 - Chirp Z-transform spectral zoom optimization with .pdf>)

## 函数原型 
```
cx_vec czt(const vec& x, const uword M, const cx_double W, const cx_double A);


cx_vec czt(const cx_vec& x, const uword M, const cx_double W, const cx_double A);
```
### 返回值

\[ X(k) = \sum_{n = 0}^{N - 1} x(n) A^{-n} W^{nk}    ,k=0,1,\cdot \cdot \cdot,M-1  \] 


