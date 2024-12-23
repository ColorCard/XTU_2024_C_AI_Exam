// 这是文件 T42.c
#include <stdio.h>

int main() {
    int x,a,y,b;
    scanf("%d %d %d %d", &x, &a, &y, &b);
    double z;
    // 可以从这里来思考，其中使得m*z=k即可：total= x*a*(m*x-k) = y*b*(m*y-k)
    z = (double)(y*b-a*x)/(b-a);
    printf("%.2f", z);

    return 0;
}
