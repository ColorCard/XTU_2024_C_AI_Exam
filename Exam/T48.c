// 这是文件 T48.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 200

struct word {
    char word[50];
};

typedef struct word Word;


void processInput(char *input, Word *wordCount, int *size) {
    char word[50];
    int len=0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            word[len++] = input[i];
        } else if (len > 0) {
            word[len] = '\0';
            len = 0;

            strcpy(wordCount[*size].word, word);
            (*size)++;

        }
    }
    // 处理最后一个单词
    if (len > 0) {
        word[len] = '\0';
        strcpy(wordCount[*size].word, word);
        (*size)++;
    }
}

int main() {
    char input[MAX_LEN];
    Word wordCount[1000];
    int size = 0;

    fgets(input, MAX_LEN, stdin);

    processInput(input, wordCount, &size);


    for (int i = 0; i < size; i++) {
        printf("%s\n", wordCount[i].word);
    }
    return 0;
}
