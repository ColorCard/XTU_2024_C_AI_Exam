// 这是文件 T45.c
#include <stdio.h>

int main() {
    int s;
    scanf("%d", &s);
    double cost;
    if(s<=3){
        cost=13;
    } else if(s<=15){
        cost=13+(s-3)*2.3;
    } else{
        cost=13+12*2.3+(s-15)*3.45;
    }

    printf("%.2f", cost);
    return 0;
}
