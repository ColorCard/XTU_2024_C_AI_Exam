#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 100

// 冒泡排序函数，用于对字符串数组按照字典序排序
int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
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
    qsort(duplicates, duplicateCount, sizeof(duplicates[0]), compare);

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
