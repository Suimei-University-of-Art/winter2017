#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#define MAXN 450
#define eps 1e-6
#define MP(a,b) make_pair((a),(b))
#define lowbit(x) ((x)&(-(x)))

using namespace std;
bool vis[MAXN+30][MAXN+30];
int val[MAXN+30],n,ans;
vector<int>adj[MAXN+30];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	adj[i].clear();
	ans=0;
	memset(vis,0,sizeof(vis));
	return ;
}
int main()
{
	int i,j,k,l,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		init();
		for(i=1;i<=n;i++)
			scanf("%d",val+i);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&j,&k);
			adj[j].push_back(k);
			vis[j][k]=1;
		}
		for(i=1;i<=n;i++)
			sort(adj[i].begin(),adj[i].end());
		for(i=1;i<=n;i++)
			for(j=0;j<adj[i].size();j++)
			{
				ans=max(ans,val[i]+val[adj[i][j]]);
				for(k=j+1;k<adj[i].size();k++)
					if(vis[adj[i][j]][adj[i][k]])
					{
						ans=max(ans,val[i]+val[adj[i][j]]+val[adj[i][k]]);
						for(l=k+1;l<adj[i].size();l++)
							if(vis[adj[i][j]][adj[i][l]]&&vis[adj[i][k]][adj[i][l]])
								ans=max(ans,val[i]+val[adj[i][j]]+val[adj[i][k]]+val[adj[i][l]]);
					}
			}
		printf("%d\n",ans);
	}
	return 0;
}