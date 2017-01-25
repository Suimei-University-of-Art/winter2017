#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int x[N];

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; i++) scanf("%d", x + i);
    LL ans = 0;
    for (int i = 1; i < n; i++) {
        ans += min(1ll * (x[i] - x[i-1]) * a, (LL)b);
    }
    printf("%lld\n", ans);
    return 0;
}
