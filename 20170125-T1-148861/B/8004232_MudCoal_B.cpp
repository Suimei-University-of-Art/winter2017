#include<stdio.h>
int n;
char s[110];
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	int x=0,max=0;
	for (int i=0;i<n;i++){
		if (s[i]=='D') x--;
		else x++;
		if (x>max) max=x;
	}
	printf("%d\n",max);
}