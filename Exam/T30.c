#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    scanf("%s", a);

    if(strlen(a)>20) {
        printf("no");
        return 0;
    }

    if(a[0] >= '0' && a[0] <= '9') {
        printf("no");
        return 0;
    }

    for (int i = 0; a[i] != '\0'; i++) {
        if((a[i]<'z'&&a[i]>'a')|| (a[i]<'Z'&&a[i]>'A')|| a[i]=='_'|| (a[i]>='0'&&a[i]<='9')) {
            continue;
        } else{
            printf("no");
            return 0;
        }
    }

    printf("yes");

    return 0;
}