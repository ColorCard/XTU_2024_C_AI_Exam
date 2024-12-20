#include <stdio.h>

int main() {
    int N,m;
    scanf("%d %d",&N,&m);

    int count=0;
    int a[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
        if(a[i]==m){
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
