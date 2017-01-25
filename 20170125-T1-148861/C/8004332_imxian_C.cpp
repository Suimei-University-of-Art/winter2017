#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1100, MOD = 1e9 + 7;
int cnt[N];

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int t = i;
        for (int j = 2; j <= t; j++) if (t % j == 0) {
            while (t % j == 0) {
                cnt[j]++;
                t /= j;
            }
        }
    }
    LL ans = 1;
    for (int i = 2; i <= n; i++) ans = ans * (cnt[i]+1) % MOD;
    cout << ans << endl;
    return 0;
}
