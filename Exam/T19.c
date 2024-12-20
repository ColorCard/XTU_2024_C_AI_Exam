#include <stdio.h>

void LED(int a[],int n,int index){
    for (int i = 0; i < n; ++i) {
        if((i+1)%index==0){
            a[i]=!a[i];
        }
    }
}

int main() {
    int N,M;
    scanf("%d %d", &N, &M);

    int a[50001];
    for (int i = 0; i < N; ++i) {
        a[i]=1;
    }

    for (int i = 1; i <= M; ++i) {
        LED(a,N,i);
    }

    int flag=0;
    for (int i = 0; i < N; ++i) {
        if(a[i]==0) {
            if(flag==0){
                printf("%d", i+1);
                flag=1;
            } else{
                printf(",%d", i+1);
            }
        }
    }

    return 0;
}
