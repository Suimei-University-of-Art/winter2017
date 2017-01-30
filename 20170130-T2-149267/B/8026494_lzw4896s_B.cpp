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

int n;
int cnt[N];

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	scanf("%d",&n); int x,a=0,b=0;
	for (int i=1;i<=n;i++) scanf("%d",&x),cnt[x]++;
	for (int i=1;i<N;i++) 
	{
		if (cnt[i]&1) a++;
		else if (cnt[i]) b++;
	}
	if (b<=1) cout<<a<<endl;
	else if (b&1) cout<<a+b-1<<endl;
	else cout<<a+b<<endl;
	return 0;
}
