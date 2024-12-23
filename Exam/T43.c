// 这是文件 T43.c
#include <stdio.h>

struct patient{
    char name[20];
    double temperature;
    int cough;
};

typedef struct patient Patient;

int main() {
    int n;
    scanf("%d", &n);
    Patient patients[n];
    int index=0;
    for (int i = 0; i < n; ++i) {
        scanf("%s %lf %d", patients[i].name, &patients[i].temperature, &patients[i].cough);
        if(patients[i].temperature>=37.5&&patients[i].cough==1){
            printf("%s\n", patients[i].name);
            index++;
        }
    }
    printf("%d", index);
    return 0;
}
