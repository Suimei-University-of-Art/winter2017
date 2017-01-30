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

using namespace std;
int a[MAXN+80];
int main()
{
	int i,j,n,L;
	scanf("%d%d",&n,&L);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<n&&a[i]+a[i+1]<L;i++);
	if(i==n)
	{
		printf("Impossible\n");
		return 0;
	}
	puts("Possible");
	for(j=1;j<i;j++)
		printf("%d\n",j);
	for(j=n-1;j>i;j--)
		printf("%d\n",j);
	printf("%d\n",i);
	return 0;
}