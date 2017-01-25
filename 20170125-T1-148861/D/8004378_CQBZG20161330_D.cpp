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
#define MAXN 100000
#define hlq 1000000007
#define pii pair<int,int>

using namespace std;
int d[MAXN+80];
long long ans,a,b;
int main()
{
	int n,i;
	scanf("%d",&n);
	cin>>a>>b;
	for(i=1;i<=n;i++)
		scanf("%d",d+i);
	for(i=1;i<n;i++)
		ans+=min(a*(d[i+1]-d[i]),b);
	cout<<ans;
	return 0;
}