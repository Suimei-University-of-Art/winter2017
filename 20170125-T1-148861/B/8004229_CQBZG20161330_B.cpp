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
#define pii pair<int,int>

using namespace std;
char s[MAXN+80];
int main()
{
	int x=0,Max=0,n,i;
	scanf("%d",&n);
	getchar();
	fgets(s,108,stdin);
	for(i=0;i<n;i++)
	{
		x+=s[i]=='I';
		x-=s[i]=='D';
		Max=max(x,Max);
	}
	printf("%d",Max);
	return 0;
}