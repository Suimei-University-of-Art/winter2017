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
#define N 1010
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1000000007;

const double INF=1e18;

bool flag[N];
int p[N],b[N];

void work(int x)
{
	for (int i=1;i<=p[0] && p[i]<=x;i++)
	{
		while (x%p[i]==0) x/=p[i],b[i]++;
	}
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	int n,ans=1; cin >> n;
	for (int i=2;i<N;i++)
	{
		if (!flag[i]) p[++p[0]]=i;
		for (int j=1;j<=p[0] && i*p[j]<N;j++)
		{
			flag[i*p[j]]=true;
			if (i%p[j]==0) break;
		}
	}
	for (int i=2;i<=n;i++) work(i);
	for (int i=1;i<=p[0];i++) ans=1ll*ans*(b[i]+1)%Mod;
	cout<<ans<<endl;
	return 0;

}
