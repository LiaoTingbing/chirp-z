
# ChirpZ

由于Armadillo没有czt变换函数，就用armadillo写了个czt变换的函数。

## 原理

[ChirpZ原理](https://blog.csdn.net/weixin_44625313/article/details/129127826)


函数原型 
```
cx_vec czt( vec x , uword m , cx_double w, cx_double a )
```
返回值

$ \sum_n^{N-1}x_n z^{-n}  $
$ z=aw^{0:M-1}  $


length-m chirp Z-transform (CZT) of x along the spiral contour on the z-plane defined by w and a through z = a*w.^-(0:m-1).