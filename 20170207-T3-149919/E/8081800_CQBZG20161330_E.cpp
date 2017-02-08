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
#define MAXN 2000
#define eps 1e-6
#define MP(a,b) make_pair((a),(b))
#define lowbit(x) ((x)&(-(x)))

using namespace std;
struct node
{
	int l,r,bal,pos;
}po[MAXN+70];
int cnt;
void build(int fa)
{
	char c=getchar();
	if(c=='B')
	{
		po[fa].bal++,po[fa].pos++,getchar();
		return ;
	}
	else if(c==')')
	{
		po[fa].pos++;
		return ;
	}
	po[fa].l=++cnt;
	build(cnt);
	po[fa].r=++cnt;
	getchar();
	build(cnt);
	getchar();
	po[fa].bal=po[po[fa].l].bal+po[po[fa].r].bal;
	po[fa].pos=po[po[fa].l].pos+po[po[fa].r].pos;
	return ;
}
bool get()
{
	char c;
	while((c=getchar())!=EOF&&c^'(');
	if(c==EOF)
		return 0;
	memset(po,0,sizeof(po));
	build(cnt=1);
	return 1;
}
int chg(int a,int b,int c)
{
	if(c>=0)
		return -((a<0)*a+(b<0)*b);
	else
		return (a>0)*a+(b>0)*b;
}
int chk(int fa,int add)
{
	int ret,all,r1,r2,t=1<<30;
	if(po[fa].bal+add<0||po[fa].bal+add>po[fa].pos)
		return -1;
	if(po[fa].l)
	{
		all=add+po[fa].bal;
		if(all&1)
		{
			r1=(all>>1)-po[po[fa].l].bal+1;
			r2=(all>>1)-po[po[fa].r].bal;
			ret=chg(r1,r2,add);
			if(~(r1=chk(po[fa].l,r1))&&~(r2=chk(po[fa].r,r2)))
				t=ret+r1+r2;
			r1=(all>>1)-po[po[fa].l].bal;
			r2=(all>>1)-po[po[fa].r].bal+1;
			ret=chg(r1,r2,add);
			if(~(r1=chk(po[fa].l,r1))&&~(r2=chk(po[fa].r,r2)))
				t=min(t,ret+r1+r2);
			if(t<(1<<30))
				return t;
		}
		else
		{
			r1=(all>>1)-po[po[fa].l].bal;
			r2=(all>>1)-po[po[fa].r].bal;
			ret=chg(r1,r2,add);
			if(~(r1=chk(po[fa].l,r1))&&~(r2=chk(po[fa].r,r2)))
				return ret+r1+r2;
		}
		return -1;
	}
	return 0;
}
int main()
{
	int t;
	while(get())
		if(~(t=chk(1,0)))
			printf("%d\n",t);
		else
			puts("impossible");
	return 0;
}