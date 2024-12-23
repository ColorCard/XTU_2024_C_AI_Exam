// 这是文件 T41.c
#include <stdio.h>
#include <stdlib.h>

struct student{
    int id;
    int chinese;
    int math;
    int english;
};

typedef struct student Student;

int compare(const void*a,const void*b){
    Student *studentA=(Student*)a;
    Student *studentB=(Student*)b;
    if(studentA->chinese+studentA->math+studentA->english!=studentB->chinese+studentB->math+studentB->english){
        return studentB->chinese+studentB->math+studentB->english-studentA->chinese-studentA->math-studentA->english;
    }
    if(studentA->chinese!=studentB->chinese){
        return studentB->chinese-studentA->chinese;
    }
    if(studentA->math!=studentB->math){
        return studentB->math-studentA->math;
    }
    if(studentA->english!=studentB->english){
        return studentB->english-studentA->english;
    }

    return studentA->id-studentB->id;
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    Student students[n];
    for (int i = 0; i < n; ++i) {
        students[i].id=i+1;
        scanf("%d %d %d",  &students[i].chinese, &students[i].math, &students[i].english);
    }

    qsort(students,n, sizeof(Student),compare);
    for (int i = 0; i < m; ++i) {
        printf("%d ", students[i].id);
    }

    return 0;
}
