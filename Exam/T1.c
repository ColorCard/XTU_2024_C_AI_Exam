//
// Created by colorcard on 24-12-18.
//
#include <stdio.h>
int main(){
        int n;
        scanf("%d",&n);
        int index=0;
        int a[100];
        for(int j=0 ; j<n; j++){
                scanf("%d",&a[j]);
                index+=a[j];
            }
        double avr=(double)index/n;
        for(int j=0 ; j<n; j++){
                if(a[j]>avr){
                        printf("%d ",a[j]);
                    }
            }
        return 0;
}