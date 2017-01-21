#include <bits/stdc++.h>

using namespace std;

int A[100010],S[100010];

int main()
{
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		int tmp = -1; //(N-X) - (X-1) = A[i]  X = N-1-A[i]
		if ((N+1-A[i])%2!=0)
		{
			puts("0");
			return 0;
		}
		else S[(N+1-A[i])/2]++;
	}
	//for (int i=1;i<=N;i++)printf("%d\n",S[i]);
	if ((N&1) && S[N/2+1]!=1)
	{
		puts("0");
		return 0;
	}
	int ans = 1;
	for (int i=1;i<=N/2;i++)
	{
		if (S[i] < 1 || S[i] > 2) 
		{
			puts("0");
			return 0;
		}
		ans *= S[i];
		ans %= 1000000007;
	}
	printf("%d\n",ans);
}