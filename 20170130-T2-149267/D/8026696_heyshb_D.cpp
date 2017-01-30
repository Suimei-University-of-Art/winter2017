#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int N,M;
struct Event
{
	int len,L,R;	
};
vector<Event>E;

Event Make(int len,int L,int R)
{
	return (Event){len,L,R};
}

int Tr[300010];
int lowbit(int x){return x&-x;}
int getsum(int x){int S=0;while(x){S+=Tr[x];x-=lowbit(x);}return S;}
void add(int x,int y){while(x<=M){Tr[x]+=y;x+=lowbit(x);}}

bool cmp(Event A,Event B)
{
	return A.len<B.len;
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)
	{
		int LL,RR;
		scanf("%d%d",&LL,&RR);
		E.push_back(Make(RR-LL+1,LL,RR));
	}
	sort(E.begin(),E.end(),cmp);
	int now = 0;
	int cnt = N;
	for (int i=1;i<=M;i++)
	{
		while(now<E.size() && E[now].len<i)
		{
			Event tmp = E[now];
			add(tmp.L,1);
			add(tmp.R+1,-1);
			now++;
			cnt--;
		}
		int ans = cnt;
		for (int j=i;j<=M;j+=i) ans+=getsum(j);
		printf("%d\n",ans);
	}
}