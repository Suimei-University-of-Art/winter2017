#include<stdio.h>
int main(){
	long long x;
	scanf("%lld",&x);
	printf("%lld",x/11*2+(x%11==0?0:(x%11<=6?1:2)));
}