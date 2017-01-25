#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1100, MOD = 1e9 + 7;
int c[N][N], g[N][N], inv[N];
int dp[N][N];

int mypow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int main() {
    for (int i = 0; i < N; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
    }
    for (int i = 1; i < N; i++) inv[i] = mypow(i, MOD - 2);
    for (int i = 1; i < N; i++) {
        g[i][0] = 1;
        for (int j = 1; j < N; j++) if (i * j < N) {
            g[i][j] = 1ll * g[i][j-1] * c[i*j][i] % MOD * inv[j] % MOD;
        }
    }
    int n, a, b, C, d;
    scanf("%d%d%d%d%d", &n, &a, &b, &C, &d);
    dp[a-1][0] = 1;
    for (int i = a; i <= b; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j];
            for (int k = C; k <= d; k++) {
                if (k * i > j) break;
                dp[i][j] = (dp[i][j] + 1ll * dp[i-1][j-k*i] * g[i][k] % MOD * c[j][k*i] % MOD) % MOD;
            }
        }
    }
    printf("%d\n", dp[b][n]);
    return 0;
}
