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
deque<int>q;
int main()
{
	int n,i,j,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		q.push_back(a[i]);
	while(q.size())
	{
		do{
			i=q.front();
			q.pop_front();
			ans++;
		}while(q.size()&&i^q.front());
		if(q.empty())
			break;
		do{
			j=q.back();
			q.pop_back();
			ans++;
		}while(q.size()&&j^q.back());
		if(q.empty()||(i==q.front()&&j==q.back()))
			ans-=2;
	}
	printf("%d",ans);
	return 0;
}