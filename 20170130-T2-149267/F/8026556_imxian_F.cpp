#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int a[N];

int main() {
    int n, L;
    scanf("%d%d", &n, &L);
    int idx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        if (i && a[i] + a[i-1] >= L) idx = i;
    }
    if (!idx) puts("Impossible");
    else {
        puts("Possible");
        for (int i = 1; i < idx; i++) printf("%d\n", i);
        for (int i = n - 1; i >= idx; i--) printf("%d\n", i);
    }
    return 0;
}
