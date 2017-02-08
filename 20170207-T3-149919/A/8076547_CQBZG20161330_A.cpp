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
int da[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
struct node{
	int y,m,d;
	int operator -(const node &x)const
	{
		int sum=0,i;
		sum+=(y-x.y)*365+((y-1)/4-x.y/4);
		for(i=1;i<m;i++)
			sum+=da[y%4==0][i];
		sum+=d;
		for(i=1;i<x.m;i++)
			sum-=da[x.y%4==0][i];
		sum-=x.d;
		return sum;
	}
	node operator +(int days)const
	{
		node x=*this;
		days+=x.d-1;
		while(x.m>1)
			days+=da[x.y%4==0&&(x.y%100!=0||x.y%400==0)][--x.m];
		x.y+=days/146097*400;
		days%=146097;
		while(days>=365+(x.y%4==0&&(x.y%100!=0||x.y%400==0)))
			days-=(365+(x.y%4==0&&(x.y%100!=0||x.y%400==0))),x.y++;
		while(days>=da[(x.y%4==0&&(x.y%100!=0||x.y%400==0))][x.m])
			days-=da[(x.y%4==0&&(x.y%100!=0||x.y%400==0))][x.m++];
		x.d=days+1;
		return x;
	}
	void P()
	{
		printf("%04d-%02d-%02d\n",y,m,d);
		return ;
	}
};
int main()
{
	node s1,s2,b;
	s1.y=1582,s1.m=10,s1.d=4;
	s2.y=1582,s2.m=10,s2.d=15;
	while(scanf("%d-%d-%d",&b.y,&b.m,&b.d)==3)
		(s2+(b-s1)).P();
	return 0;
}