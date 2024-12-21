#include <stdio.h>

int main() {
    double n;
    scanf("%lf", &n);

    double income=n-60000;
    double tax=0;

    if(income<=0){
        tax=0;
    } else if(income<=36000){
        tax=income*0.03;
    } else if(income<=144000){
        tax=income*0.1-2520;
    } else if(income<=300000){
        tax=income*0.2-16920;
    } else if(income<=420000){
        tax=income*0.25-31920;
    } else if(income<=660000){
        tax=income*0.3-52920;
    } else if(income<=960000){
        tax=income*0.35-85920;
    } else {
        tax=income*0.45-181920;
    }



    printf("%.0lf", tax);

    return 0;
}
