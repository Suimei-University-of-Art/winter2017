#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll i,j,k,n,ans;
int main(){
	while (scanf("%lld",&n)!=EOF){
		ans=n/11*2;k=n%11;
		if (k&&k<=6) ans++;
		if (k>6) ans+=2;
		printf("%lld\n",ans);
	}
	return 0;
}