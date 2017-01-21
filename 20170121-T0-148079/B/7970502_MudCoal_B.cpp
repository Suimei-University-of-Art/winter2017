#include<stdio.h>
#define N (200)
int n,m;
int a[N];
int main(){
	scanf("%d",&n);
	int s=0;
	for (int i=1;i<=n;i++) scanf("%d",a+i),s+=a[i];
	scanf("%d",&m);
	for (int i=1,b,c;i<=m;i++){
		scanf("%d%d",&b,&c);
		printf("%d\n",s-a[b]+c);
	}
}