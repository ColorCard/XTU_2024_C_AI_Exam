#include <stdio.h>
#include <string.h>

void spread(char a[100][100], int n) {
    char temp[100][100];

    memcpy(temp, a, sizeof(temp));//复制到暂用数组

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '@') { // 如果当前房间已经得流感
                // 传染四个方向
                if (i - 1 >= 0 && a[i - 1][j] == '.') {
                    temp[i - 1][j] = '@'; // 上
                }
                if (i + 1 < n && a[i + 1][j] == '.') {
                    temp[i + 1][j] = '@'; // 下
                }
                if (j - 1 >= 0 && a[i][j - 1] == '.') {
                    temp[i][j - 1] = '@'; // 左
                }
                if (j + 1 < n && a[i][j + 1] == '.') {
                    temp[i][j + 1] = '@'; // 右
                }
            }
        }
    }

    memcpy(a, temp, sizeof(temp));//复制回来
}

int main() {
    int n;
    scanf("%d", &n);
    char a[100][100];

    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }

    int day;
    scanf("%d", &day);

    for(int k=0;k<day-1;k++){
        spread(a,n);
    }

    int count=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j]=='@'){
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}
