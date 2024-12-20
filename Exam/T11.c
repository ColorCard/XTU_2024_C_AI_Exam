#include <stdio.h>

int main() {
    long long n,x,y;
    scanf("%lld %lld %lld", &n, &x, &y);
    if(y>=x*n){
        printf("0");
    } else if(y%x==0){
        printf("%lld", n-(y/x));
    }else {
        printf("%lld", n-(y/x)-1);
    }

}
