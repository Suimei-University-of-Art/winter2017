#include<stdio.h>
int a,c;
char b[10];
int main(){
	scanf("%d%s%d",&a,b,&c);
	if (b[0]=='+') printf("%d\n",a+c);
	else printf("%d\n",a-c);
}