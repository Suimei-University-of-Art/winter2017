#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N,A,B,X[100010];

int main()
{
	scanf("%d%d%d",&N,&A,&B);
	for (int i=1;i<=N;i++)scanf("%d",&X[i]);
	LL ans=0;
	for (int i=2;i<=N;i++)
	ans+=min(LL(A)*LL(X[i]-X[i-1]),LL(B));
	cout<<ans<<endl;
}