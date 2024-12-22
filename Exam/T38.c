// 这是文件 T38.c
#include <stdio.h>


struct student{
    char name[20];
    int end_socre;
    int class_socre;
    int section1;
    int section2;
    int article;
    int sum;
};

int main() {
    int N;
    scanf("%d", &N);
    struct student students[N];
    for (int i = 0; i < N; ++i) {
        scanf("%s %d %d", students[i].name, &students[i].end_socre, &students[i].class_socre);
        getchar();
        if(getchar()=='Y'){
            students[i].section1=1;
        } else{
            students[i].section1=0;
        }
        getchar();
        if(getchar()=='Y'){
            students[i].section2=1;
        } else{
            students[i].section2=0;
        }
        scanf("%d", &students[i].article);
    }

    for (int i = 0; i < N; ++i) {
        students[i].sum=0;
        if(students[i].end_socre>80&&students[i].article>=1){
            students[i].sum+=8000;
        }
        if(students[i].end_socre>85&&students[i].class_socre>80){
            students[i].sum+=4000;
        }
        if(students[i].end_socre>90){
            students[i].sum+=2000;
        }
        if(students[i].end_socre>85&&students[i].section2==1){
            students[i].sum+=1000;
        }
        if(students[i].class_socre>80&&students[i].section1==1){
            students[i].sum+=850;
        }

    }

    int max=0;
    int index=0;
    for (int i = 0; i < N; ++i) {
        if(students[i].sum>max){
            max=students[i].sum;
            index=i;
        }
    }

    int sum=0;
    for (int i = 0; i < N; ++i) {
        sum+=students[i].sum;
    }

    printf("%s\n%d\n%d\n", students[index].name, students[index].sum, sum);


    return 0;
}
