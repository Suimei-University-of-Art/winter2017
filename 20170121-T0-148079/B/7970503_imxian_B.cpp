#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 110;
int a[N];

int main() {
    int n, m, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), sum += a[i];
    scanf("%d", &m);
    while (m--) {
        int p, x;
        scanf("%d%d", &p, &x);
        printf("%d\n", sum - a[p] + x);
    }
    return 0;
}
