#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int N,L;
int A[100010]; 

int main()
{
	scanf("%d%d",&N,&L);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
	}
	bool ok = false;
	int last;
	for (int i=1;i<N;i++)
	{
		if (A[i] + A[i+1] >= L) 
		{
			ok = true;
			last = i;
		}
	}
	if (!ok)
		puts("Impossible");
	else
	{
		puts("Possible");
		for (int i=1;i<last;i++)printf("%d\n",i);
		for (int i=N-1;i>last;i--)printf("%d\n",i);
		printf("%d\n",last);
	}
}