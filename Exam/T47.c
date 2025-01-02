// 这是文件 T47.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 200

struct word {
    char word[50];
};

typedef struct word Word;

int compare(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

void processInput(char *input, Word *wordCount, int *size) {
    char word[50];
    int len=0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            word[len++] = tolower(input[i]);
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

    qsort(wordCount, size, sizeof(Word), compare);

    for (int i = 0; i < size; i++) {
        printf("%s ", wordCount[i].word);
    }
    return 0;
}
