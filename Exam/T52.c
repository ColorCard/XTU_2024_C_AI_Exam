// 这是文件 T52.c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum = 1; 

    for (int i = n - 1; i >= 1; i--) {
        sum = (sum + 1) * 2;  // 根据每天吃桃的规律倒推前一天桃子的数量
    }

    printf("%d\n", sum);

    return 0;
}
