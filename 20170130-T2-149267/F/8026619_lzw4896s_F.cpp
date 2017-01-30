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

int n,L;
int a[N];

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	bool flag=false; int d;
	scanf("%d%d",&n,&L);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) if (a[i]+a[i+1]>=L) flag=true,d=i;
	if (!flag) printf("Impossible\n");
	else
	{
		printf("Possible\n");
		for (int i=1;i<d;i++) printf("%d\n",i);
		for (int i=n-1;i>=d;i--) printf("%d\n",i);
	}
	return 0;
}
