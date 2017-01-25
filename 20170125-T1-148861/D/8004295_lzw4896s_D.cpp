#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <queue>
using namespace std;

#define X first
#define Y second
#define N 100010
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1000000007;

const double INF=1e18;
typedef long long ll;
int x[N];


int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	int n,a,b; scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	
	ll ans=0;
	for (int i=2;i<=n;i++)
	{
		ans+=min(1ll*(x[i]-x[i-1])*a,1ll*b);
	}
	cout<<ans<<endl;
	
	return 0;
}
