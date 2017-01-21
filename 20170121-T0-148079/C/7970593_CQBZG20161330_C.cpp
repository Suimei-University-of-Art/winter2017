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
#define hlq 1000000007

using namespace std;
int a[MAXN+8];
int pow_2_mod(int x)
{
	int ans=1;
	long long t=2;
	while(x)
	{
		if(x&1)
			ans=ans*t%hlq;
		t=t*t%hlq;
		x>>=1;
	}
	return ans;
}
bool chk(int x)
{
	int i;
	if(x&1)
	{
		if(a[1])
			return 0;
		for(i=2;i<=x;i+=2)
			if((a[i]!=i)||(a[i+1]!=i))
				return 0;
		return 1;
	}
	for(i=1;i<=x;i+=2)
		if((a[i]!=i)||(a[i+1]!=i))
			return 0;
	return 1;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	if(chk(n))
		printf("%d",pow_2_mod(n>>1));
	else
		putchar('0');
    return 0;
}