#include <stdio.h>
#include <math.h>

int main() {
    double height;
    double g=9.8;
    scanf("%lf", &height);
    double time = sqrt(2*height/g);
    printf("%.2lf", time);

}
