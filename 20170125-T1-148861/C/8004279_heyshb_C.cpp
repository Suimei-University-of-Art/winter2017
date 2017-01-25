#include <bits/stdc++.h>

using namespace std;

int T[1010],prime[1010],cnt;
bool ok[1010];
typedef long long LL;
LL MOD = 1000000007;

int main()
{	
	memset(ok,true,sizeof(ok));
	for (int i=2;i<=1000;i++)
	{
		if (ok[i]) prime[++cnt]=i;
		for (int j=2*i;j<=1000;j+=i)ok[j]=false;
	}
	//for (int i=1;i<=cnt;i++)printf("%d\n",prime[i]);
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		int tmp=i;
		for (int j=1;j<=cnt;j++)
		{
			while(tmp%prime[j]==0)
			{
				tmp/=prime[j];
				T[j]++;
			}
		}
	}
	LL ans=1;
	for (int i=1;i<=cnt;i++)ans=ans*LL(T[i]+1)%MOD;
	cout<<ans<<endl;
}