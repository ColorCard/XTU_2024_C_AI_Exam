// 这是文件 T37.c
#include <stdio.h>
#include <stdlib.h>

struct student{
    int id;
    int chinese;
    int math;
    int english;
};

typedef struct student Student;

int compare(const void *a, const void *b) {
    if (((Student *)b)->chinese+((Student *)b)->math+((Student *)b)->english != ((Student *)a)->chinese+((Student *)a)->math+((Student *)a)->english) {
        return ((Student *)b)->chinese+((Student *)b)->math+((Student *)b)->english - ((Student *)a)->chinese+((Student *)a)->math+((Student *)a)->english;
    } else if (((Student *)b)->chinese != ((Student *)a)->chinese) {
        return ((Student *)b)->chinese - ((Student *)a)->chinese;
    } else {
        return ((Student *)a)->id - ((Student *)b)->id;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Student students[n];
    for (int i = 0; i < n; ++i) {
        students[i].id=i+1;
        scanf("%d %d %d",  &students[i].chinese, &students[i].math, &students[i].english);
    }

    qsort(students, n, sizeof(Student), compare);

    for (int i = 0; i < 5; ++i) {
        printf("%d  %d\n", students[i].id, students[i].chinese+students[i].math+students[i].english);
    }
    return 0;
}
