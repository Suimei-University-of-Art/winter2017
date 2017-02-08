#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
int x, y, z;
int a, b, c;

void prework(){

}

void read(){

}

ll maki[MAXN];
int g[MAXN];
int mp[MAXN];
int cnt[MAXN];

int gao[MAXN];
int honoka[26] = {0, 0, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 2};

void solve(int casi){
	for(int i = 16; i >= 1; i--){
		a = (int)(exp(log(x) / i) + 1e-8);
		int ret = 1;
		for(int j = 1; j <= i; j++)
			ret *= a;
		if (ret == x){
			b = i;
			break;
		}
	}
	for(int i = 1; i <= n; i++){
		cnt[i] = 0;
	}
	while(mp[b] > 0){
		cnt[-mp[mp[b]]]++;
		b /= mp[b];
	}
	cnt[-mp[b]]++;
	x = y;
	for(int i = 16; i >= 1; i--){
		a = (int)(exp(log(x) / i) + 1e-8);
		int ret = 1;
		for(int j = 1; j <= i; j++)
			ret *= a;
		if (ret == x){
			b = i;
			break;
		}
	}
	z *= b;
	while(mp[a] > 0){
		cnt[-mp[mp[a]]] += z;
		a /= mp[a];
	}
	cnt[-mp[a]]+=z;
	vector<int> nico;
	for(int i = 1; i <= n; i++)
		if (cnt[i]){
			nico.push_back(cnt[i]);
		}
	sort(nico.begin(), nico.end());
/*	puts("==========================");
	cout<<nico.size()<<endl;
	for(auto &umi : nico){
		cout<<(umi)<<' ';
	}cout<<endl;
*/		
	m = nico[nico.size() - 1];
	ll ans = 0;
	for(int i = 2; i <= m; i++){
		maki[i] = 1;
		int flag = 1;
		for(auto &umi : nico){
			maki[i] *= (umi / i + 1);
			//if (umi % i != 0) flag = 0;//meiyongwan!
		}
		maki[i] -= 1;// + flag;
	}
	//for(int i = 1; i <= m; i++)
	//	cout<<maki[i]<<' '; cout<<endl;
	for(int i = 2; i <= m; i++){
		ans += gao[i] * maki[i];
		//for(int j = i + i; j <= m; j += i)
		//	ans -= maki[j];
	}
	printf("%lld\n", ans);
}

int eli[MAXN], nozo[MAXN];

int main(){
	n = 0; mp[1] = 0;
	int _ = 9585 * 16 + 17;
	for(int i = 2; i <= _; ){
		for(int j = i + i; j <= _; j += i)
			if (mp[j] == 0) mp[j] = i;
		g[++n] = i;
		mp[i] = -n;
		while(i <= _ && mp[i]) i++;
	}
	gao[0] = -1;
	gao[1] = 1;
	eli[1] = nozo[1] = 1;
	for(int i = 25; i >= 2; i--){
		for(int j = 2; j < i; j++)
			if (i % j == 0)
				honoka[i] += honoka[j];
	}
	for(int i = 2; i <= _; i++){
		if (mp[i] < 0) eli[i] = i, nozo[i] = 1, gao[i] = 1;
		else{
			eli[i] = i, nozo[i] = 1;
			for(int j = 20; j >= 1; j--){
				int tmp = (int)(exp(log(i) / j) + 1e-7);
				if (i % tmp == 0 && tmp == eli[i / tmp] && j == nozo[i / tmp] + 1){
					eli[i] = tmp;
					nozo[i] = j;
					break;
				}
			}
		}
		gao[i] = honoka[nozo[i]] + 1;
	}
	gao[1] = 0;
//	for(int i = 1; i <= 64; i++)
//		cout<<i<<' '<<gao[i]<<' '<<eli[i]<<'^'<<nozo[i]<<endl;
	while(scanf("%d^%d^%d", &x, &y, &z) != EOF){
		solve(0);
	}
	return 0;
}


