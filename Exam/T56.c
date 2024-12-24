#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 100

// 冒泡排序函数，用于对字符串数组按照字典序排序
void bubbleSort(char arr[][MAX_NAME_LENGTH], int size) {
    int i, j;
    char temp[MAX_NAME_LENGTH];
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main() {
    int m, n;
    scanf("%d", &m);
    char studentsA[MAX_STUDENTS][MAX_NAME_LENGTH];
    for (int i = 0; i < m; i++) {
        scanf("%s", studentsA[i]);
    }

    scanf("%d", &n);
    char studentsB[MAX_STUDENTS][MAX_NAME_LENGTH];
    for (int i = 0; i < n; i++) {
        scanf("%s", studentsB[i]);
    }

    // 找出重复选课的同学，使用一个临时数组来记录重复的同学
    char duplicates[MAX_STUDENTS][MAX_NAME_LENGTH];
    int duplicateCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(studentsA[i], studentsB[j]) == 0) {
                strcpy(duplicates[duplicateCount], studentsA[i]);
                duplicateCount++;
            }
        }
    }

    // 对重复选课的同学数组进行排序
    bubbleSort(duplicates, duplicateCount);

    // 输出重复选课的同学姓名
    for (int i = 0; i < duplicateCount; i++) {
        if (i!= 0) {
            printf(" ");
        }
        printf("%s", duplicates[i]);
    }
    printf("\n");

    return 0;
}
