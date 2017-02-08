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
#define N 460
#define M 1000010
typedef long long ll;
typedef pair<int,int> pii;

int v[N];
bool mp[N][N];
pii e[N*2];

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	int n,m,ans; 
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		ans=0; memset(mp,0,sizeof(mp));
		for (int i=1;i<=n;i++) scanf("%d",&v[i]);
		for (int i=1;i<=m;i++)
		{
			int x,y; scanf("%d%d",&x,&y);
			mp[x][y]=mp[y][x]=true;
			e[i].X=x; e[i].Y=y;
			ans=max(ans,v[x]+v[y]);
		}
	
		for (int i=1;i<=m;i++)
		{
			for (int j=i+1;j<=m;j++)
			{
				set<int> st;  
				st.insert(e[i].X);
				st.insert(e[i].Y);
				st.insert(e[j].X);
				st.insert(e[j].Y);
				set<int> ::iterator iter=st.begin();
				
				int p[4],t=0; bool flag=true;
				while (iter!=st.end())
				{
					p[t++]=*iter;
					iter++;
				}
				for (int k1=0;k1<t;k1++)
					for (int k2=k1+1;k2<t;k2++)
						if (!mp[p[k1]][p[k2]]) flag=false;
				if (flag)
				{
					int cur=0;
					for (int k=0;k<t;k++) cur+=v[p[k]];
					ans=max(ans,cur);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
