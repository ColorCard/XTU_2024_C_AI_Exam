// 这是文件 T58.c
#include <stdio.h>

int main() {
    int weight;  
    char urgent;  
    scanf("%d %c", &weight, &urgent);

    int fee = 8;  
    if (weight > 1000) {
        
        int extra = weight - 1000;
        fee += (extra + 499) / 500 * 4;
    }
    if (urgent == 'y') {
        fee += 5;  
    }

    printf("%d\n", fee);

    return 0;
}
