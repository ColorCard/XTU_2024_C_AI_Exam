// 这是文件 T26.c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count=0;
    if(n%3==0) {
        count++;
        printf("3 ");
    }
    if(n%5==0){
        count++;
        printf("5 ");
    }
    if(n%7==0) {
        count++;
        printf("7 ");
    }

    if(count==0){
        printf("n");
    }

    return 0;
}
