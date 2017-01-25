#include<stdio.h>
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int x=a*b,y=c*d;
	printf("%d\n",x<y?y:x);
}