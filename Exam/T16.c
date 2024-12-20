#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}//升序

int in_compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}//降序

int main() {
    int a[11];
    for (int i = 0; i < 11; ++i) {
        scanf("%d", &a[i]);
    }
    if (a[0] == 1) {
        qsort(a+1, 10, sizeof(int), compare);
    }else{
        qsort(a+1, 10, sizeof(int), in_compare);
    }

    for (int i = 1; i < 11; ++i) {
        printf("%d ", a[i]);
    }

}
