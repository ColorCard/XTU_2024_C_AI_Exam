#include <stdio.h>

int main() {
    int lucky,encourage;
    scanf("%d %d", &lucky, &encourage);

    if(lucky>=10||encourage>=20){
        printf("1");
    } else{
        printf("0");
    }
    return 0;
}