#include <bits/stdc++.h>

using namespace std;

int N,T[110],M,P[110],X[110];

int main()
{
	scanf("%d",&N);
	int ans = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&T[i]);
		ans+=T[i];
	}
	scanf("%d",&M);
	int save = 10000000;
	for (int i=1;i<=M;i++)
	{
		scanf("%d%d",&P[i],&X[i]);
		printf("%d\n",ans + X[i] - T[P[i]]);
	}
	//printf("%d\n", ans-save);
}