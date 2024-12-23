#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum=1;
    for (int i = 0; i < n-1; ++i) {
        sum=(sum+1)*2;
    }
    printf("%d", sum);
    return 0;
}