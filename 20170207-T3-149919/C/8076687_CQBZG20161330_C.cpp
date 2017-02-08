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
#define MAXN 100000
#define pii pair<long long,long long>
#define MP(a,b) make_pair((a),(b))
#define lowbit(x) ((x)&(-(x)))

using namespace std;
int gcd(int a,int b)
{
	int t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
struct node{
	int x,y;
	void simplify()
	{
		int g=gcd(x,y);
		x/=g;
		y/=g;
		return ;
	}
	void P()
	{
		printf("%d/%d\n",y,x);
		return ;
	}
}fraction;
int main()
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		fraction.y=a*b;
		fraction.x=c-b;
		fraction.simplify();
		fraction.P();
	}
	return 0;
}