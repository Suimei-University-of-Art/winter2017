#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E3 + 10;
const int INF = MAXN << 1;

char s[MAXN * 5];
int n, size[MAXN << 1];
int f[MAXN << 1][MAXN];

inline int g(int i, int j){
	return j <= size[i] ? f[i][j] : INF;
}

int DFS(int u, const char *(&p)){
	if (*++p == 'B')
		return size[u] = 1, p += 2, f[u][1] = 0, f[u][0] = 1;
	else if (*p == ')')
		return size[u] = 1, p += 1, f[u][1] = 1, f[u][0] = 0;
	else{
		int l, r;
		int ret = DFS(l = ++n, p);
		ret += DFS(r = ++n, p);
		size[u] = size[l] + size[r];
		for (int i = 0; i <= size[u]; ++i)
			f[u][i] = min(INF, min(g(l, i >> 1) + g(r, i + 1 >> 1), g(l, i + 1 >> 1) + g(r, i >> 1)));
		return p += 1, ret;
	}
}

int main(){
	while (scanf("%s", s) != EOF){
		const char *p = s;
		int ans = f[1][DFS(n = 1, p)];
		if (ans < INF)
			printf("%d\n", ans >> 1);
		else
			puts("impossible");
	}
	return 0;
}
