#include <bits/stdc++.h>

using namespace std;

int N;
char s[1010];

int main()
{
	scanf("%d",&N);
	scanf("%s",s+1);
	int ans=0,tmp=0;
	for (int i=1;i<=N;i++)
	{
		if (s[i]=='D') tmp--;
		else tmp++;
		ans=max(ans,tmp);
	}
	printf("%d\n",ans);
}