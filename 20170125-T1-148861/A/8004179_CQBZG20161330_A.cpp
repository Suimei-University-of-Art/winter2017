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
#define pii pair<int,int>

using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d",max(a*b,c*d));
	return 0;
}