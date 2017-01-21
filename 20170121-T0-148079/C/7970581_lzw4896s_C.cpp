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

int n;
int a[N],cnt[N];

int Solve1()
{
	int res=1;
	if (cnt[0]!=1) return 0;

	for (int i=2;i<n;i+=2)
	{
		if (cnt[i]!=2) return 0;
		res=1ll*res*2%Mod;
	}
	return res;
}

int Solve2()
{
	int res=1;
	for (int i=1;i<n;i+=2)
	{
		if (cnt[i]!=2) return 0;
		res=1ll*res*2%Mod;
	}
	return res;
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	
	if (n&1) printf("%d\n",Solve1());
	else printf("%d\n",Solve2());
	
	return 0;

}
