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

int K;
ll C[2222][2222];
ll pw[2222];
ll f[2222][2222];
ll sum[2222][2222];

void solve(int casi){
	cin>>n>>K;
	C[0][0] = C[1][0] = C[1][1] = 1;
	for(int i = 2; i <= 2000; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MM;
	}
	pw[0] = 1;
	for(int i = 1; i <= 2000; i++){
		pw[i] = (2 * pw[i-1]) % MM;
	}
	ll ans = 0;//pw[n-K-1];
	f[0][0] = 1;
	for(int i = 0; i <= n; i++)
		sum[0][i] = 1;
	for(int i = 1; i < K; i++){
		for(int j = 0; j <= n - i; j++){
			f[i][j] = sum[i-1][j+1];
		}
		sum[i][0] = f[i][0];
		for(int j = 1; j <= n - i; j++)
			sum[i][j] = (sum[i][j-1] + f[i][j]) % MM;
	}
	for(int i = 0; i <= n - K; i++)
		ans = (ans + f[K-1][i]) % MM;
	cout<<((K!=n)?(ans * pw[n-K-1] % MM):ans)<<endl;
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



