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
#define N 100010
#define M 400010
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1000000007;

ll Solve(ll x)
{
	if (x<=6) return 1;
	if (x<=11) return 2;
	
	ll ans=x/11*2; x%=11;
	if (x==0) return ans;
	if (x<=6) return ans+1;
	return ans+2;
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	ll x; 
	cin >> x;
	cout<< Solve(x)<<endl;
	return 0;
}
