#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;
const ll INF = 1ll << 60;

int n, m;

ll f[MAXN][2];

int a[MAXN];

void prework(){

}

int b[MAXN];

void read(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		char s[10];
		if (i < n){
			scanf("%s", s);
			if (s[0] == '+')
				b[i + 1] = 1;
			else
				b[i + 1] = -1;
		}
	}
	b[0] = b[1] = 1;
	f[0][0] = 0;
	f[0][2] = f[0][1] = -INF;
	for(int i = 1; i <= n; i++){
		if (b[i] == 1){
			f[i][1] = max(f[i-1][1] - a[i], f[i-1][2] + a[i]);
			f[i][2] = f[i-1][2] + a[i];
			f[i][0] = max(f[i-1][0] + a[i], f[i-1][1]);
		}
		else{
			f[i][2] = max(f[i-1][1] + a[i], f[i-1][2] - a[i]);
			f[i][0] = max(f[i-1][0] - a[i], f[i][2]);
			f[i][1] = f[i][0];
		}
		//cout<<f[i][0]<<' '<<f[i][1]<<endl;
	}
	cout<<max(f[n][1],max(f[n][0], f[n][2]))<<endl;
}

void solve(int casi){

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


