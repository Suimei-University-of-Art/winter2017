#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int N,S[100010],A[100010];
int L = 0, R = 0;

int main()
{
	scanf("%d",&N);
	int ans = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		if (!S[A[i]]) ans++;
		S[A[i]]++;
	}
	if ((N-ans)&1) ans--;
	printf("%d\n",ans);
}