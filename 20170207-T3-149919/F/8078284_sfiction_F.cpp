#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIP;

const int MAXN = 2E3 + 10;

int a[MAXN][MAXN];
PIP b[MAXN * MAXN];
vector<PII> E[MAXN];
int c[MAXN][MAXN];

int fa[MAXN];

int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void DFS(int c[], int u, int pre){
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i].st) == pre)
			continue;
		c[v] = c[u] + E[u][i].nd;
		DFS(c, v, u);
	}
}

int main(){
	int n;
	bool flag = false;
	while (scanf("%d", &n) != EOF){
		if (flag)
			puts("");
		flag = true;

		int m = 0;
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j)
				scanf("%d", a[i] + j), b[m++] = PIP(a[i][j], PII(i, j));
			E[i].clear();
		}
		sort(b, b + m);
		for (int i = 1; i <= n; ++i)
			fa[i] = i;
		int tot = n;
		for (int i = 0; tot > 1 && i < m; ++i){
			int u = b[i].nd.st, v = b[i].nd.nd;
			int ru = find(u), rv = find(v);
			if (ru != rv){
				--tot;
				fa[ru] = rv;
				E[u].push_back(PII(v, b[i].st));
				E[v].push_back(PII(u, b[i].st));
				printf("%d %d %d\n", u, v, b[i].st);
			}
		}

		for (int i = 1; tot && i <= n; ++i){
			c[i][i] = 0;
			DFS(c[i], i, 0);
		}
		for (int i = 0; i < m; ++i){
			int u = b[i].nd.st, v = b[i].nd.nd;
			if (c[u][v] > a[u][v]){
				--tot;
				printf("%d %d %d\n", u, v, a[u][v]);
				break;
			}
		}
		if (tot)
			puts("1 2 1000000");
	}
	return 0;
}
