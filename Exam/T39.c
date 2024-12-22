#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 2000

typedef struct {
    char word[50];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;
    if (wordA->count != wordB->count) {
        return wordB->count - wordA->count;  // 按频次降序排序
    }
    return strcmp(wordA->word, wordB->word);  // 频次相同按字典序升序
}

void processInput(char *input, WordCount *wordCounts, int *size) {
    char word[50];
    int len = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            word[len++] = tolower(input[i]);// 转换为小写字母，并存进word里面
        } else if (len > 0) {
            word[len] = '\0';
            len = 0;

            // 查找是否已存在
            int found = 0;
            for (int j = 0; j < *size; j++) {
                if (strcmp(wordCounts[j].word, word) == 0) {
                    wordCounts[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(wordCounts[*size].word, word);
                wordCounts[*size].count = 1;
                (*size)++;//引用变量，所以要加上括号
            }
        }
    }
    if (len > 0) {  // 处理最后一个单词
        word[len] = '\0';
        int found = 0;
        for (int j = 0; j < *size; j++) {
            if (strcmp(wordCounts[j].word, word) == 0) {
                wordCounts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(wordCounts[*size].word, word);
            wordCounts[*size].count = 1;
            (*size)++;
        }
    }
}

int main() {
    char input[MAX_LEN];
    WordCount wordCounts[1000];
    int size = 0;

    // 输入字符串
    fgets(input, MAX_LEN, stdin);

    // 处理输入
    processInput(input, wordCounts, &size);

    // 排序
    qsort(wordCounts, size, sizeof(WordCount), compare);

    // 输出结果
    printf("%s %d\n", wordCounts[0].word, wordCounts[0].count);

    return 0;
}