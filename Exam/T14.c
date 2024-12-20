#include <stdio.h>

int main() {
    int a[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    int index_x=0,index_y=0;
    int min=(2^31)-1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(a[i][j] < min){
                index_x = i;
                index_y = j;
                min = a[i][j];
            }
        }
    }

    printf("%d  %d  %d", index_x, index_y, a[index_x][index_y]);//注意是两个空格！！
}
