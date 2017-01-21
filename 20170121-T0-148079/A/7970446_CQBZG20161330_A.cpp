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

using namespace std;
int main()
{
	long long a,b;
	char c;
	cin>>a;
	while((c=getchar())!=EOF&&c^'+'&&c^'-');
	cin>>b;
	if(c=='+')
		cout<<a+b;
	else if(c=='-')
		cout<<a-b;
    return 0;
}