#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

int gcd(int p, int  q){
	return q ? gcd(q, p % q) : p;
}

int main(){
	int h, x, y;
	while(scanf("%d%d%d", &h, &x, &y) != EOF){
		int p = x * h;
		int q = y - x;
		int r = gcd(p, q);
		printf("%d/%d\n", p/r, q/r);
	} 
	return 0;
}


