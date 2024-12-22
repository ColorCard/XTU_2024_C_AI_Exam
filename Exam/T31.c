// 这是文件 T31.c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return -(*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[10000];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    printf("%d  %d", a[0], a[n-1]);

    return 0;
}
