// 这是文件 T39.c
#include <stdio.h>
#include <string.h>

struct string{
    char a[100][100];
    int count[100];
};

typedef struct string String;


int main() {
    String s;
    int temp[100];
    int index=0;
    while (scanf("%s", temp) != EOF) {
        int flag=0;
        for (int i = 0; i < index; ++i) {
            if(strcmp(s.a[i],temp)==0){
                s.count[i]++;
                flag=1;
                break;
            }
        }
        if(flag==0){
            strcpy(s.a[index],temp);
            s.count[index]=1;
            index++;
        }
    }

    int max=0;
    int max_index=0;
    for (int i = 0; i < index; ++i) {
        if(s.count[i]>max){
            max=s.count[i];
            max_index=i;
        } else if(s.count[i]==max){
            if(strcmp(s.a[i],s.a[max_index])<0){
                max_index=i;
            }

        }
    }

    printf("%s %d", s.a[max_index], s.count[max_index]);



    return 0;
}
