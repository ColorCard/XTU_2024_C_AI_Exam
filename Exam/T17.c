#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long sum=0;
    long long index=1;
    for (int i = 1; i <= n; ++i) {
        index*=i;
        sum+=index;
    }
    printf("%lld", sum);
}
