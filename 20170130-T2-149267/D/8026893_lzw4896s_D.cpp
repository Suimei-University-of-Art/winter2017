#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define X first
#define Y second
#define N 300010
#define M 400010
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1000000007;

int n,m;
int c[N];
vector<pii> g[N];

inline int Lowbit(int x){return x&(-x);}

void Add(int x,int v)
{
	while (x<=m)
	{
		c[x]+=v;
		x+=Lowbit(x);
	}
}

int Val(int x)
{
	int res=0;
	while (x)
	{
		res+=c[x];
		x-=Lowbit(x);
	}
	return res;
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int l,r; scanf("%d%d",&l,&r);
		g[r-l+1].push_back(make_pair(l,r));
	}
	int sz=0;
	for (int i=1;i<=m;i++)
	{
		int x=i,res=0;
		do
		{
			res+=Val(x);
			x+=i;
		}while (x<=m);
		
		for (int j=0;j<g[i].size();j++)
		{
			Add(g[i][j].X,1);
			Add(g[i][j].Y+1,-1);
		}
		printf("%d\n",res+n-sz);
		sz+=g[i].size();
	}
	return 0;
}
