#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;

int n, m;

void prework(){

}

void read(){

}

const ll INF = 1ll << 60;
ll f[MAXN][MAXN], g[MAXN][MAXN];

int isDigit(char ch){
	return ch >= '0' && ch <= '9';
}

char s[MAXN];

void solve(int casi){
	n = strlen(s+1);
	for(int i = 0; i <= n + 1; i++)
		for(int j = max(0, i - 10); j <= n + 1; j++){
			f[i][j] = INF;//min
			g[i][j] = -INF;//max
		}
	s[0] = s[n+1] = 0;
	for(int i = n; i >= 1; i--){
		if (isDigit(s[i])){
			f[i][i] = g[i][i] = s[i] - '0';
			if (s[i] != '0')
				for(int j = 1; j <= 8; j++)
					if (isDigit(s[i+j])){
						f[i][i+j]=g[i][i+j]=f[i][i+j-1]*10+f[i+j][i+j];
					}
					else break;
		}
	}
	for(int k = 1; k < n; k++){
		for(int i = 1, j = 1 + k; j <= n; i++, j++){
			if (s[i] == '-'){
				f[i][j] = min(-g[i+1][j], f[i][j]);
				g[i][j] = max(-f[i+1][j], g[i][j]);
				for(int l = i + 1; l < j; l++){
					f[i][j] = min(f[i][j], f[i+1][l] - g[l+1][j]);
					g[i][j] = max(g[i][j], g[i+1][l] - f[l+1][j]);
				}
			}
			if (s[i] == '+'){
				for(int l = i + 1; l < j; l++){
					f[i][j] = min(f[i][j], f[i+1][l] + f[l+1][j]);
					g[i][j] = max(g[i][j], g[i+1][l] + g[l+1][j]);
				}
			}
		}
	}
	printf("%lld %lld\n", f[1][n], g[1][n]);
}

void printans(){

}


int main(){
	while(scanf("%s", s + 1) != EOF){
		solve(0);
	}
	return 0;
}


