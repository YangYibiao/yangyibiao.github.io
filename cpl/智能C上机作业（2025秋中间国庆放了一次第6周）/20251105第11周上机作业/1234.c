#include<stdio.h>
#include<math.h>

double f(double x) {
    return exp(3 * x) + pow(x, 7);  // 计算函数值
}

int main(void) {
    double a = 1.0, b = 3.0;  // 积分区间[1,3]
    double h, s, x;
    long n = 100000;  
    
    h = (b - a) / n;  
    s = (f(a) + f(b)) / 2.0;
    
    x = a;
    for (long i = 1; i < n; i++) {  
        x += h;
        s += f(x);
    }
    
    s *= h;  
    printf("%.3f\n", s);  
    
    return 0;
}