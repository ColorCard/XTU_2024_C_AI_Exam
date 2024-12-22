// 这是文件 T32.c
#include <stdio.h>

int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    int index= 1;
    for (int i = 0; i < b; ++i) {
        index*=a;
        index%=1000;
    }

    printf("%03d", index);

    return 0;
}
