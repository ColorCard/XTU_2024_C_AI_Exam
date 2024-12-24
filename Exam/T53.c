// 这是文件 T53.c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum = n;
    for (int i = 9; i >= 1; i--) {
        sum = (sum + 1) * 2;
    }
    printf("%d\n", sum);
    return 0;
}
