#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <queue>
using namespace std;

#define X first
#define Y second
#define N 100010
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1000000007;

const double INF=1e18;

char s[N];

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	int n,x=0,ans=0; scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++)
	{
		if (s[i]=='I') x++;
		else x--;
		ans=max(ans,x);
	}
	cout<<ans<<endl;
	return 0;

}
