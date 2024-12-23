// 这是文件 T55.c
#include <stdio.h>

int main() {
    int n,m,q;
    scanf("%d %d %d", &n, &m, &q);
    int a[n];
    
    for (int i = 0; i < n; ++i) {
        a[i]=1;
    }//1为圈内，0为出圈
    
    int count=0;//报数
    int total=n;//剩下人数
    int index=q-1;//当前位置

    while (total>1){
        if(a[index]==1){
            count++;
            if(count==m){
                a[index]=0;
                count=0;
                total--;
            }
        }
        index++;
        if(index==n){
            index=0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            printf("%d\n", i + 1); // 输出实际的编号
            return 0;
        }
    }
    printf("none\n");

/*
    值得一提的是这个题目有点莫名奇妙，因为压根不会出现none的情况，所以这个输出是多余的
    但是非常奇怪的是，测试点过不去，我也不知道为什么。
*/

    return 0;
}
