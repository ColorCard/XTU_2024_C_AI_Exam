//
// Created by colorcard on 24-12-19.
//

#include <stdio.h>

int judge(const int a[],int n,int m){
    for (int i = 0; i < n; ++i) {
        if(a[i]==m){
            return 1;
        }
    }
    return 0;
}

int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    int b[M];

    for (int i = 0; i < M; ++i) {
        b[i]=-1;
    }

    int a[N];
    int index=0;
    int temp=0;
    for (int i = 0; i < N; ++i) {
        scanf("%d",&a[i]);
        if(judge(b,M,a[i])==0){
            if(temp<M){
                b[temp]=a[i];
                index++;
                temp++;
            } else{
                for (int j = 0; j < M-1; ++j) {
                    b[j]=b[j+1];
                }
                b[M-1]=a[i];
                index++;
            }
        }else{
            continue;
        }
    }

    printf("%d\n",index);
    return 0;
}