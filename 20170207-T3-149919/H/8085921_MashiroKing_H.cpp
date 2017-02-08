#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<PII, int> PPI;
typedef pair<int, int> PLL;
typedef pair<PLL, int> PPL;
typedef pair<PLL, PLL> PPP;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int gcd(int p, int q){
	return q ? gcd(q, p % q) : p;
}

int E[11111][111];
int t[MAXN], v[MAXN];
int __GCD[10005][105];

void solve(int casi){
	for(int i = 1; i <= 10000; i++)
		for(int j = 1; j <= 100; j++)
			E[i][j] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &t[i], &v[i]);
		E[t[i]][v[i]]++;
	}
	int ans = 0;
	map<PPL, PPI> nico;
	for(int i = 1; i <= 10000; i++)
		for(int j = 1; j <= 100; j++)
			if (E[i][j]){
				nico.clear();
				//nico[PPL(PLL(i, 0), 1)].second += E[i][j];
				//nico[PPL(PLL(i, 0), 1)].first = PII(i, j);
				for(int k = max(1, i - 99); k <= i; k++){
					for(int l = 1; l < j; l++) if (E[k][l]){
						int p = i * j - l * k, q = j - l;
						if (p < 0) continue;
						int r = (q == 0) ? p : __GCD[p % q][q];//__GCD[p][q]; //gcd(p, q);
						p /= r, q /= r;
						int pp = j * (p - q * i);
						if (pp < 0 || pp > 100 * q) continue;
						r = (q == 0) ? pp : __GCD[pp % q][q];
						pp /= r, q /= r;
						//auto maki = nico.find(PPL(PLL(p, pp), q));
						/*
						if (maki == nico.end()) {
							nico[PPL(PLL(p, pp), q)] = PPI(PII(i, j), E[i][j] + E[k][l]);
						}
						else {
							if (maki->second.first != PII(i, j)){
								maki->second.second += E[i][j];
								maki->second.first = PII(i, j);
							}
						}*/
						nico[PPL(PLL(p, pp), q)].second += E[k][l];
					}
				}
				for(auto umi : nico){
					ans = max(ans, umi.second.second + E[i][j]);
				}
				ans = max(ans, E[i][j]);
			}
	printf("%d\n", ans);
}

void printans(){

}


int main(){
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
			__GCD[i][j] = gcd(i, j);
	while(scanf("%d", &n) != EOF){
		solve(0);
	}
	return 0;
}


