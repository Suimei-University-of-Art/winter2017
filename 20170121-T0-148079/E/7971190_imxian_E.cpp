#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int a[N], ri[N];
char b[N];
LL sum[N];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%d", &a[1]);
    for (int i = 2; i <= n; i++) scanf(" %c %d", b + i, a + i);
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    ri[n + 1] = n + 1;
    for (int i = n; i >= 2; i--) {
        ri[i] = ri[i+1];
        if (b[i+1] == '-') ri[i] = i + 1;
    }
    LL ans = -1e18;
    LL tmp = a[1];
    for (int i = 2; i <= n; i++) {
        if (b[i] == '-') {
            LL ans1 = tmp - a[i] - (sum[ri[i]-1]-sum[i]) + (sum[n] - sum[ri[i]-1]);
            ans = max(ans1, ans);
        }
        if (b[i] == '-') tmp -= a[i];
        else tmp += a[i];
    }
    ans = max(ans, tmp);
    printf("%lld\n", ans);
    return 0;
}
