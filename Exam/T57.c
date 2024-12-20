// 这是文件 T57.c
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[80];
    fgets(str, 80, stdin);  

    for (int i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {  
            if (str[i] == 'z') {
                str[i] = 'a';
            } else if (str[i] == 'Z') {
                str[i] = 'A';
            } else {
                str[i]++;  
            }
        }
    }
    printf("%s", str);

    return 0;
}
