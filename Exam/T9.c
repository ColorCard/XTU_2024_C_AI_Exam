#include <stdio.h>

struct student {
    char name[20];
    int score;
};

typedef struct student Student;

void sort(Student *students, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(students[j].score < students[j + 1].score) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}//冒泡排序

int main() {
    int n;
    scanf("%d", &n);
    Student students[n];
    for(int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
    }
    sort(students, n);

    for(int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].name, students[i].score);
    }

    return 0;
}
