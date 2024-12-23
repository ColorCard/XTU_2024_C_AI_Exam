// 这是文件 T44.c
#include <stdio.h>

int main() {
    double x,n;
    scanf("%lf %lf", &x, &n);

    for (int i = 0; i < n; ++i) {
        x= x+x*0.1/100;
    }
    printf("%.4f", x);
    return 0;
}
