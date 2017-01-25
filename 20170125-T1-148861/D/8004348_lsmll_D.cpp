#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
ll ans;
int i,j,k,n,m,c1,c2,a[210001];
int main(){
	while (scanf("%d%d%d",&n,&c1,&c2)!=EOF){
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		for (ans=0,i=1;i<n;i++) ans+=min((ll)c1*(ll)(a[i+1]-a[i]),(ll)c2);
		cout<<ans<<endl;
	}
	return 0;
}