#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5E2 + 10, MAXM = 1E3 + 10;

int n, m;
int s[MAXN];
int a[MAXN][MAXN];
int e[MAXM][2];

int main(){
	while (scanf("%d%d", &n, &m) != EOF){
		int ans = 0;
		for (int i = 1; i <= n; ++i){
			scanf("%d", s + i);
			ans = max(ans, s[i]);
			fill_n(a[i] + 1, n, 0);
		}
		for (int i = 0; i < m; ++i){
			scanf("%d%d", e[i], e[i] + 1);
			a[e[i][0]][e[i][1]] = a[e[i][1]][e[i][0]] = 1;
		}
		for (int u, v, i = 0; i < m; ++i){
			u = e[i][0], v = e[i][1];
			ans = max(ans, s[u] + s[v]);
			for (int j = 1; j <= n; ++j)
				if (a[u][j] && a[v][j])
					ans = max(ans, s[u] + s[v] + s[j]);
			for (int j = 0; j < i; ++j)
				if (a[u][e[j][0]] && a[u][e[j][1]] && a[v][e[j][0]] && a[v][e[j][1]])
					ans = max(ans, s[u] + s[v] + s[e[j][0]] + s[e[j][1]]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
