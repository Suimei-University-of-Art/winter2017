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
#define N 1200
#define M 1000010
typedef long long ll;
typedef pair<int,int> pii;

int n,m;
double dp[N];
bool vis[N];


int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		char s[2]; int v,cur=m;
		memset(vis,0,sizeof(vis));
		vis[m]=true,dp[m]=1;
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s);
			if (strlen(s)==2) v=10;
			else
			{
				if (s[0]>='2' && s[0]<='9') v=s[0]-'0';
				else if (s[0]=='A') v=11;
				else v=10;
			}
			if (i==n) continue; cur+=v; vis[cur]=true; dp[cur]=1;
		}
		for (int i=1;i<=11;i++) dp[cur+i]=0;
		for (int i=cur;i>=1;i--)
		{
			if (vis[i]) continue;
			dp[i]=0;
			for (int j=2;j<=9;j++) dp[i]+=dp[i+j]/(double)13;
			dp[i]+=dp[i+10]*(double)4/13;
			dp[i]+=dp[i+11]/(double)13;
		}
		double ans=0;
		for (int i=1;i<=10;i++) ans+=dp[i]/(double)10;
		printf("%.8lf\n",ans);
	}
	
	return 0;
}
