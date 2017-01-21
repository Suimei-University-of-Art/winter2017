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
#define N 62
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1000000007;

const double INF=1e18;


int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	int a,b; char op;
	scanf("%d %c %d",&a,&op,&b);
	if (op=='+') printf("%d\n",a+b);
	else printf("%d\n",a-b);
	
	return 0;

}
