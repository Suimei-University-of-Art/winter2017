#include<stdio.h>
#include<algorithm>
#define N (100010)
typedef long long LL;
int x[N],d[N];
int main(){
	int n,a,b;
	LL ans=0;
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++) scanf("%d",x+i);
	for (int i=2;i<=n;i++) d[i]=x[i]-x[i-1];
	std::sort(d+2,d+n+1);
	for (int i=n;i>1;i--){
		if (1ll*d[i]*a>1ll*b){
			ans+=b;
		}
		else {
			for (int j=2;j<=i;j++){
				ans+=1ll*a*d[j];
			}
			break;
		}
	}
	printf("%lld\n",ans);
}