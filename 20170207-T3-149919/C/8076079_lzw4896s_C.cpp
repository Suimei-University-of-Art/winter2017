#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define X first
#define Y second
#define N 1200010
#define M 1000010
typedef long long ll;
typedef pair<int,int> pii;

int gcd(int x,int y)
{
	int tmp;
	while (y)
	{
		tmp=x%y;
		x=y,y=tmp;
	}
	return x;
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);

	int a,b,c;
	while (scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		int x=a*b,y=c-b,d=gcd(x,y);
		printf("%d/%d\n",x/d,y/d);
	}
	return 0;
}
