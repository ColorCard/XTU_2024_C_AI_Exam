//
// Created by colorcard on 24-12-19.
//
#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);

    int index=0;
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d",&temp);
        index+=(temp+69)/70;
    }

    printf("%.1lf",index*0.1);

    return 0;
}