#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int main()
{
	LL x,M,ans;
	cin>>x;
	M = x % 11;
	ans = (x/11)*2;
	if (M > 0)
	{
		if (M<=6) ans++;
		else ans+=2;
	}
	cout<<ans<<endl;
}