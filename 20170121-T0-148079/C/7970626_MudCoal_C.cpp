#include<stdio.h>
#define N (100010)
#define MD (1000000007)
int n,ans,a[N],f[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i),f[a[i]]++;
	if (n&1){
		if (f[0]!=1) ans=0; else ans=1;
		for (int i=2;i<n;i+=2){
			if (f[i]!=2){
				ans=0;
				break;
			}
			else {
				ans=ans*2%MD;
			}
		}
	}
	else {
		ans=1;
		for (int i=1;i<n;i+=2){
			if (f[i]!=2){
				ans=0;
				break;
			}
			else {
				ans=ans*2%MD;
			}
		}
	}
	printf("%d\n",ans);
}