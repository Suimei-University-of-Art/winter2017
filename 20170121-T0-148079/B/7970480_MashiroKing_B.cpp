#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int a[MAXN];

void solve(int casi){
	cin>>n;
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	cin>>m;
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", sum  - a[x] + y);
	}
}

void printans(){

}


int main(){
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}


