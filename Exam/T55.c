#include <stdio.h>

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    // 特殊情况处理：如果 m=1，所有猴子都会被淘汰
    if (m == 1) {
        printf("none\n");
        return 0;
    }

    int monkeys[1000] = {0};
    for (int i = 1; i <= n; i++) {
        monkeys[i] = 1;
    }

    int count = n;      // 记录当前剩余的猴子数量
    int position = q;   // 当前报数位置
    int number = 1;     // 当前报的数

    while (count > 1) {
        if (monkeys[position] == 1) {
            if (number == m) {
                monkeys[position] = 0;
                count--;
                number = 1;
            } else {
                number++;
            }
        }

        position++;
        if (position > n) {
            position = 1;
        }
    }

    if (count == 1) {
        for (int i = 1; i <= n; i++) {
            if (monkeys[i] == 1) {
                printf("%d\n", i);
                return 0;
            }
        }
    }

    printf("none\n");
    return 0;
}