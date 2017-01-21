#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
char op[100010];
int v[100010];
LL INF = LL(1e17);
LL s1[100010],s2[100010];

//A-(B-(C-(D-E)))  = A-B+C-D+E  = A-(B-C) - (D-E)
vector <int> negpos; 

int main()
{
	scanf("%d",&N);
	scanf("%d",&v[1]);
	s1[0] = s2[0] = 0;
	op[1] = '+';
	for (int i=2;i<=N;i++)
	{
		scanf(" %c %d",&op[i],&v[i]);
		if (op[i] == '-') negpos.push_back(i);
	}
	for (int i=1;i<=N;i++)
	{
		s1[i] = s1[i-1] + LL(v[i]) * (op[i]=='+'?1:-1);
		s2[i] = s2[i-1] + LL(v[i]);
	}
	//for (int i=1;i<=N;i++)printf("%d %c %I64d %I64d\n",v[i],op[i],s1[i],s2[i]);
	LL ans = s1[N];
	int SZ = negpos.size();
	for (int i=0;i<SZ-1;i++)
	{
		int p1,p2;
		p1 = negpos[i];
		p2 = negpos[i+1];
		//printf("%d %d %I64d\n",p1,p2,s1[p1-1] - (s1[p2-1]-s1[p1-1]) + (s2[N]-s2[p2-1]));
		ans = max(ans,s1[p1-1] - (s2[p2-1]-s2[p1-1]) + (s2[N]-s2[p2-1]));
	}
	cout<<ans<<endl;
}

