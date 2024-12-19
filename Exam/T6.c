//
// Created by colorcard on 24-12-19.
//
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a = 0,b=0,c=0,d=0;
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        if(temp>=0&&temp<=18){
            a++;
        }else if(temp>=19&&temp<=35) {
            b++;
        } else if(temp>=36&&temp<=60){
            c++;
        } else{
            d++;
        }
    }

    printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%\n", a*100.0/n, b*100.0/n, c*100.0/n, d*100.0/n);

    return 0;
}