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
#define N 110
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1000000007;

const double INF=1e18;

int n,m;
int s[N],t[N],a[N],b[N];

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&t[i]),s[i]=t[i]+s[i-1];
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		printf("%d\n",s[a[i]-1]+s[n]-s[a[i]]+b[i]);
	}
	
	return 0;

}
