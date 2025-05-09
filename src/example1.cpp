
 

#include "../include/czt.h"
#include <ctime>

const double PI = 3.1415926; 
int main()
{

    uword N = 20000000;
    double f1 = 100;
    double f2 = 101;
    double fs = 8000;
    double Ts = 1.0 / fs;
    vec ts = linspace(1,N,N) * Ts;
    cx_vec x =( exp(-cx_double(0, 1)*2.0* PI * f1 * ts) + cos(2 * PI * f2 * ts))  ;
    int m = 100000; 
    cx_double w = exp(-cx_double(0, 1) * 2.0 * PI * double(150 - 50) / (m * fs));
    cx_double a = exp(cx_double(0,1) * 2.0 * PI * 50.0 / fs);
    auto start = clock();
    vec y_CZT = abs(czt ( (x), m, w, a)); 
    auto send = clock();
    cout << "耗时：" << double(send - start) / CLOCKS_PER_SEC << endl;

    
    return 0;
}