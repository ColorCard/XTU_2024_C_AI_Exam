#include <stdio.h>

int findNthDigitOfFraction(int a, int b, int n) {
    int i, result;
    a %= b;

    for (i = 0; i < n; i++) {
        a *= 10;
        result = a / b;
        a %= b;
    }

    return result;
}

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);

    int nthDigit = findNthDigitOfFraction(a, b, n);
    printf("%d", nthDigit);

    return 0;
}