#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mm=1000000007,lim=1005;
int i,j,k,n,m,ans,a[1111];
int main(){
	while (scanf("%d",&n)!=EOF){
		ans=1;
		for (i=1;i<=n;i++) a[i]=i;
		for (i=2;i<=n;i++){
			for (j=1,k=0;j<=n;j++)
			 for (;a[j]%i==0;a[j]/=i) k++;
			ans=(ll)ans*(ll)(k+1)%mm;
		}
		printf("%d\n",ans);
	}
	return 0;
}