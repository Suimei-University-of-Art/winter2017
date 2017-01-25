#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <queue>
using namespace std;

#define X first
#define Y second
#define N 1010
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1000000007;

const double INF=1e18;
typedef long long ll;

int x[N],dp[N][N];
int c[N][N],fac[N],fac_inv[N];

int Power(int a,int p)
{
	int res=1;
	for (;p;p>>=1)
	{
		if (p&1) res=1ll*res*a%Mod;
		a=1ll*a*a%Mod;
	}
	return res;
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	int n,A,B,C,D;
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%Mod;
	for (int i=0;i<N;i++) fac_inv[i]=Power(fac[i],Mod-2);
	cin >> n >> A >> B >> C >> D;
	c[0][0]=1;
	for (int i=1;i<N;i++)
	{
		c[i][0]=1;
		for (int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%Mod;
	}
	dp[0][0]=1;
	for (int i=0;;i++)
	{
		int v=i+A;
		if (v>B) break;
		for (int j=0;j<=n;j++)
		{
			if (dp[i][j]==0) continue;
			dp[i+1][j]+=dp[i][j];
			dp[i+1][j]%=Mod;
			int t=n-j,tmp=1;
			for (int k=1;t>=0;k++)
			{
				tmp=1ll*tmp*c[t][v]%Mod;
				if (k>=C && k<=D) 
				{
					dp[i+1][j+k*v]+=(1ll*dp[i][j]*tmp%Mod)*fac_inv[k]%Mod;
					dp[i+1][j+k*v]%=Mod;
				}
				t-=v;
			}
		}
	}
	printf("%d\n",dp[B-A+1][n]);
	return 0;
}
