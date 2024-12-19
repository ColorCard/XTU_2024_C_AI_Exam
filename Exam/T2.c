//
// Created by colorcard on 24-12-19.
//
#include <stdio.h>

int main(){
    int a[10];
    for(int i=0; i<10; i++){
        scanf("%d",&a[i]);
    }

    printf("%.1lf",a[0]*28.9+a[1]*32.7+a[2]*45.6+a[3]*78+a[4]*35+a[5]*86.2+a[6]*27.8+a[7]*43+a[8]*56+a[9]*65);

    return 0;
}