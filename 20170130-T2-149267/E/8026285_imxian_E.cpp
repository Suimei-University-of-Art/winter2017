#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    LL n;
    cin >> n;
    LL m = n / 11;
    n -= m * 11;
    LL ans = 2 * m + (n > 0) + (n > 6);
    cout << ans << endl;
    return 0;
}
