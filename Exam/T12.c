#include <stdio.h>
#include <math.h>

int main() {
    int h,r;
    scanf("%d %d",&h,&r);
    double v=3.14159*r*r*h;
    printf("%.0lf",ceil(20*1000/v));
}
