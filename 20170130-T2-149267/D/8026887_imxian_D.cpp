#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 3e5 + 10, M = 1e5 + 10;
int n, m;
int l[N], r[N], idx[N], len[N];
int a[M];

bool cmp(int x, int y) {
    return len[x] < len[y];
}

void add(int x, int v) {
    for (; x <= m + 1; x += x & -x) a[x] += v;
}

int query(int x) {
    int ret = 0;
    for (; x; x -= x &-x) ret += a[x];
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", l + i, r + i); 
        len[i] = r[i] - l[i] + 1;
        idx[i] = i;
    }
    sort(idx, idx + n, cmp);
    int j = 0;
    for (int i = 1; i <= m; i++) {
        while (j < n && len[idx[j]] < i) {
            add(l[idx[j]], 1);
            add(r[idx[j]]+1, -1);
            j++;
        }
        int ans = 0;
        for (int k = i; k <= m; k += i) ans += query(k);
        printf("%d\n", ans + n - j);
    }
    return 0;
}
