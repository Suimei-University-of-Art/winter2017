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

using namespace std;
//int a[7][2]={0,0,1,0,2,1,3,1,4,1,5,1,6,2};
int main()
{
	long long x,ans=0;
	cin>>x;
	ans+=x/11*2;
	x%=11;
	if(x>0)
	{
		if(x>6)
			ans++;
		ans++;
	}
	cout<<ans;
	return 0;
}