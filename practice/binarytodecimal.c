#include<stdio.h>
int main(){
	int number;
	int decimalnumber=0;
	printf("WRITE A NUMBER: ");
	scanf("%d",&number);
	for (int i=0;number!=0;i++){
	int remainder=number%10; 
	number=number/10;
    decimalnumber+=remainder*(1 << i);
		}
		printf("decimal number is %d\n",decimalnumber);
		
	
	
	
}