#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 1000 + 10;

int n, m;

void prework(){

}

void read(){

}

int a[MAXN];
int d[MAXN][MAXN];
vector<int> E[MAXN];
int x[MAXN], y[MAXN];

void solve(int casi){
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ans = max(ans, a[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			d[i][j] = 0;
		E[i].clear();
	}
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &x[i], &y[i]);
		d[x[i]][y[i]] = d[y[i]][x[i]] = 1;
		ans = max(ans, a[x[i]]+a[y[i]]);
		E[x[i]].push_back(y[i]);
		E[y[i]].push_back(x[i]);
	}
	
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cout<<d[i][j]<<' ';
		cout<<endl;
	}
	*/
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			if (d[i][x[j]] && d[i][y[j]] && i != x[j] && i != y[j])
				ans = max(ans, a[i] + a[x[j]] + a[y[j]]);
		/*
		for(int j = 0; j < E[i].size(); j++){
			for(int k = j + 1; k < E[i].size(); k++){
				if (d[E[i][j]][E[i][k]]){
					ans = max(ans, a[i] + a[E[i][j]] + a[E[i][k]]);
				}
			}
		}*/
	}
	for(int i = 1; i <= m; i++)
		for(int j = i + 1; j <= m; j++){
			int e = x[i], b = y[i], c = x[j], f = y[j];
			if (e != c && e != f && b != c && b != f){
				if ((d[e][c] && d[b][f] && d[e][f] && d[b][c]) || (d[e][c] && d[b][f] && d[e][f] && d[b][c])){
					//cout<<b<<' '<<c<<' '<<e<<' '<<f<<endl;
					ans = max(ans, a[b] + a[c] + a[e] + a[f]);
				}
			}
		}
	printf("%d\n", ans);
}

void printans(){

}


int main(){
	while(scanf("%d%d", &n, &m) != EOF){
		solve(0);
	}
	return 0;
}


