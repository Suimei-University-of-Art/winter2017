#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int i,j,k,n,m,ans,a[110001],s[110001];
int main(){
	while (scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		for (i=m=1;i<=n;i++) scanf("%d",&k),a[k]++,m=max(m,k);
		for (i=1,s[0]=0;i<=m;i++) s[i]=s[i-1]+a[i];
		for (i=1,ans=n,j=m;i<=j;){
			while (a[i]<=1&&i<=j) i++;
			while (a[j]<=1&&i<=j) j--;
			if (i>j) break;
			if (i!=j) k=min(a[i],a[j])-1,a[i]-=k,a[j]-=k,ans-=2*k;else{
				if (a[i]&1) ans-=(a[i]-1);else ans-=a[i];
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}