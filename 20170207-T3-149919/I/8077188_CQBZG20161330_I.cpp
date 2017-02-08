#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#define MAXN 1100
#define eps 1e-6
#define MP(a,b) make_pair((a),(b))
#define lowbit(x) ((x)&(-(x)))

using namespace std;
double p[MAXN+70];
int get()
{
	char c;
	while((c=getchar())!=EOF&&isalnum(c)==0);
	if(isalpha(c))
		return 10+(c=='A');
	if(getchar()=='0')
		return 10;
	return c-'0';
}
int main()
{
	int n,m,i,j,l;
	double t,P;
	while(scanf("%d%d",&n,&m)==2)
	{
		t=P=0;
		memset(p,0,sizeof p);
		for(i=1;i<=n;i++)
		{
			p[m]=1;
			l=m;
			m+=get();
		}
		for(i=l;i;i--)
		{
			if(p[i]<eps)
			{
				for(j=2;j<=9;j++)
					p[i]+=p[i+j]/13;
				p[i]+=p[i+j]/13*4+p[i+11]/13;
			}
		}
		for(i=1;i<=10;i++)
			P+=p[i]/10;
		printf("%.25f\n",P);
	}
	return 0;
}