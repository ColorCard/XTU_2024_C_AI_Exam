// 这是文件 T51.c
#include <stdio.h>

int main(void){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    int e;
    e = ((b+c-a)%12+12)%12;
    if(e == 0){
        printf("12");
    }
    else{
        printf("%d",e);
    }
    
}
