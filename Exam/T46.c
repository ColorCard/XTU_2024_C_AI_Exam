// 这是文件 T46.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverse_string(char* str) {
    if (str == NULL) return;

    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}//双指针法反转字符串

int main() {
    char a[200];
    fgets(a, 200, stdin);
    for (int i = 0; i < strlen(a); ++i) {
        if(islower(a[i])){
            a[i]=toupper(a[i]);
        } else if(isupper(a[i])){
            a[i]=tolower(a[i]);
        }
        if(a[i]>='a'&&a[i]<='z'){
            a[i]=(a[i]+3-'a')%26+'a';
        } else if(a[i]>='A'&&a[i]<='Z'){
            a[i]=(a[i]+3-'A')%26+'A';
        }
    }

    reverse_string(a);

    puts(a);

    return 0;
}
