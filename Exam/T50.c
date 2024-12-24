#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[100];
    for (int i = 0; i < n; ++i) {
        a[i]=1;
    }
    int count=0;
    int index=0;
    int num=0;
    while(count<n-1){
        if(a[index]==1){
            num++;
            if(num==3){
                a[index]=0;
                count++;
                num=0;
            }
        }
        index++;
        if(index==n){
            index=0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(a[i]==1){
            printf("%d号猴子是大王。", i+1);
        }
    }
    return 0;
}