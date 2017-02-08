#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1 << 17;
const int f0[] = {1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1};

int f[MAXN + 1];
int up[MAXN + 1];
ll g[MAXN + 1];

vector<PII> factor(int x){
	vector<PII> ret;
	for (int i = 2; i * i <= x; ++i){
		if (x % i)
			continue;
		ret.emplace_back(i, 1);
		for (x /= i; x % i == 0; x /= i, ++ret.back().nd);
	}
	if (x > 1)
		ret.emplace_back(x, 1);
	return ret;
}

int main(){
	fill_n(f, MAXN + 1, 1);
	fill_n(up, MAXN + 1, 1);
	for (int i = 2; i * i <= MAXN; ++i)
		for(int t = i * i, j = 2; t <= MAXN; t *= i, ++j)
			f[t] += f0[j], up[t] = max(up[t], j);
	for (int i = MAXN >> 1; i >= 2; --i)
		for (int j = i << 1; j <= MAXN; j += i)
			f[j] += f[i];

	int a, b, c;
	while (scanf("%d^%d^%d", &a, &b, &c) != EOF){
		auto da = factor(up[a]), db = factor(b);
		transform(db.begin(), db.end(), db.begin(), [c](const PII &t){return PII(t.st, t.nd * c);});
		for (int j, i = 0; i < da.size(); ++i){
			for (j = 0; j < db.size(); ++j)
				if (db[j].st == da[i].st){
					db[j].nd += da[i].nd;
					break;
				}
			if (j == db.size())
				db.push_back(da[i]);
		}
		int m = 1;
		for (int i = 0; i < db.size(); ++i)
			m = max(m, db[i].nd);

		for (int i = 2; i <= m; ++i){
			g[i] = 1;
			for (int j = 0; j < db.size(); ++j)
				g[i] *= db[j].nd / i + 1;
			--g[i];
		}
		ll ans = 0;
		for (int i = m; i >= 2; --i){
			for (int j = i << 1; j <= m; j += i)
				g[i] -= g[j];
			ans += g[i] * f[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
