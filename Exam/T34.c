// 这是文件 T34.c
#include <stdio.h>

int main() {
    int chinese,math;
    scanf("%d %d", &chinese, &math);

    if(chinese>=60&&math>=60){
        printf("0");
    } else if(chinese>=60||math>=60){
        printf("1");
    } else{
        printf("0");
    }
    return 0;
}
