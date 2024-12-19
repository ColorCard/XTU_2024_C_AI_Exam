//
// Created by colorcard on 24-12-19.
//
#include <stdio.h>

int main(){
    double h;
    scanf("%lf",&h);
    double sum_height=0;
    for (int i = 0; i < 10; ++i) {
        sum_height+=h;
        h/=2;
        sum_height+=h;
    }

    printf("%.4lf\n%.4lf",sum_height-h,h);

    return 0;
}