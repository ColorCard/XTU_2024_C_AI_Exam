// 这是文件 T40.c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    return -(*(int *)a-*(int *)b);
}//降序

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    qsort(a,n, sizeof(int),compare);

    printf("%d", a[0]);
    return 0;
}
