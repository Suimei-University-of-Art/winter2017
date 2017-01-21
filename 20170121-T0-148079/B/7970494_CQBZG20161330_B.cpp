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
#define MAXN 100

using namespace std;
int t[MAXN+8],p[MAXN+8],x[MAXN+8];
int main()
{
	int n,m,i,S=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",t+i),S+=t[i];
	scanf("%d",&m);
	for(i=1;i<=m;i++)
		scanf("%d%d",p+i,x+i);
	for(i=1;i<=m;i++)
		printf("%d\n",S-t[p[i]]+x[i]);
    return 0;
}