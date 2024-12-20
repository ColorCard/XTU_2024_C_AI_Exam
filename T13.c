#include<stdio.h> 

int main()
{
	int i,cnt=0,time=0;
	int school[7] = {0}, mom[7] = {0};  
	for(i=0;i<7;i++){
		scanf("%d %d", &school[i], &mom[i]);
	}
	for(i=0;i<7;i++){
		if(school[i]+mom[i]>8 && school[i]+mom[i]>time){ 
			time = school[i]+mom[i];  
			cnt = i+1;  
		}
	}
	printf("%d",cnt);
	return 0;
}
//try to pr
