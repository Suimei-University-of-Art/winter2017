#include<stdio.h>
#define MD (1000000007)
int f[1010];
int main(){
	int n,ans=1;
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		if (!f[i]){
			int s=0;
			for (int k=n/i;k>0;k/=i){
				s+=k;
			}
			ans=1ll*ans*(s+1)%MD;
			for (int j=i*i;j<=n;j+=i){
				f[j]=1;
			}
		}
	}
	printf("%d\n",ans);
}