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
#define MAXN 1000
#define hlq 1000000007
#define pii pair<int,int>

using namespace std;
bool vis[MAXN+80];
int pri[MAXN];
int num[MAXN];
void chk(int x)
{
	int j=1;
	while(x>1)
	{
		while(x%pri[j]==0)
		{
			x/=pri[j];
			num[j]++;
		}
		j++;
	}
	return ;
}
int main()
{
	long long ans=1;
	int i,j,n;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
		if(vis[i]==0)
		{
			pri[++pri[0]]=i;
			for(j=i*i;j<=n;j+=i)
				vis[j]=1;
		}
	for(i=1;i<=n;i++)
		chk(i);
	for(i=1;i<=pri[0];i++)
		ans=ans*(num[i]+1)%hlq;
	printf("%d",(int)ans);
	return 0;
}