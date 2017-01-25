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

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	cout<<max(a*b,c*d)<<endl;
	return 0;

}
