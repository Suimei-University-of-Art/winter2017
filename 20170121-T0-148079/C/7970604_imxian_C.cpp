#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9 +7;
const int N = 1e5 + 10;
int a[N], b[N];

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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d",  a + i);
        b[i] = abs((n - i - 1) - i);
    }
    sort(a, a + n);
    sort(b, b + n);
    bool flag = true;
    for (int i = 0; i < n; i++) if (a[i] != b[i]) {
        flag = false;
        break;
    }
    if (!flag) puts("0");
    else printf("%d\n", mypow(2, n / 2));
    return 0;
}
