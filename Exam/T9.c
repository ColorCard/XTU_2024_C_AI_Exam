#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[20];
    int score;
};

typedef struct student Student;

int compare(const void *a, const void *b) {
    return ((Student *)b)->score - ((Student *)a)->score;
}//降序

int main() {
    int n;
    scanf("%d", &n);
    Student students[n];
    for(int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
    }
    qsort(students, n, sizeof(Student), compare);

    for(int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].name, students[i].score);
    }

    return 0;
}
