#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
bool flag[N];
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (flag[x]) cnt++;
        else flag[x] = true;
    }
    printf("%d\n", n - cnt - (cnt & 1));
    return 0;
}
