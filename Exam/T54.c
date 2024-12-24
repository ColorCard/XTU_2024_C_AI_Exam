#include <stdio.h>

void Chicken(int m, int n, int *c, int *r) {
    *c = (4 * m - n) / 2;
    *r = m - *c;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int chicken, rabbit;
    Chicken(m, n, &chicken, &rabbit);
    printf("共有%d只鸡\n", chicken);
    printf("共有%d只兔\n", rabbit);
    return 0;
}
