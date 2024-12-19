#include <stdio.h>

int main() {
    int water;
    scanf("%d", &water);
    double price = 0;
    if (water <= 15) {
        price = water * 2.58;
    } else if (water <= 22) {
        price = 15 * 2.58 + (water - 15) * 3.34;
    } else {
        price = 15 * 2.58 + 7 * 3.34 + (water - 22) * 4.09;
    }
    printf("%.0lf\n", price*100);
}
