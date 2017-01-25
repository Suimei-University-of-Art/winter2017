#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int MOD = 1000000007;

int N,A,B,C,D;
LL F[1010][1010];
int up = 1000;
LL fac[1010];
LL inv[1010];

typedef long long LL;

LL po(LL x,int a)
{
	LL res = 1;
	while(a)
	{
		if (a&1) 
			res = res * x % MOD;
		x = x * x % MOD;
		a>>=1;
	}
	return res;
}

LL Co(LL N,LL M)
{
	return ((fac[N]*inv[M])%MOD)*inv[N-M]%MOD;
}

LL calc(int S,int x)//x the sizeof leftmost group
{
	if (S == 0) return 1;
	if (x > B) return 0;
	if (F[S][x] != -1) return F[S][x];
	LL res = calc(S,x+1);
	for (int i=C;i<=D;i++)
	{
		if (i * x > S) break;
		LL tmp = calc(S-i*x, x+1); 
		//printf("%d %d %d %I64d\n",S,x,i,tmp);
		tmp = tmp * inv[i] % MOD;
		tmp = tmp * po(inv[x], i) % MOD;
		res = (res + tmp) % MOD;
	}
	return F[S][x] = res;
}

int main()
{
	fac[0] = 1;
	for (int i=1;i<=up;i++)fac[i] = fac[i-1] * i % MOD;
	inv[up] = po(fac[up],MOD-2);
	for (int i=up-1;i>=1;i--) inv[i] = inv[i+1] * (i+1) % MOD;
	//for (int i=1;i<=100;i++)printf("%I64d %I64d \n",fac[i],inv[i]);
	scanf("%d%d%d%d%d",&N,&A,&B,&C,&D);
	for (int i=0;i<=N;i++)
		for (int j=0;j<=N;j++)F[i][j] = -1;
	LL ans = 0;
	ans = calc(N,A)*fac[N]%MOD;
	//for (int i=1;i<=N;i++)
	//	for (int j=1;j<=N;j++)
	//	if (F[i][j]!=-1)printf("[%d][%d] = %d\n",i,j,F[i][j]);
	cout<<ans<<endl;
}