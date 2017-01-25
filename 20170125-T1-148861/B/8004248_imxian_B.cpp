#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 110;
char s[N];

int main() {
    int n;
    scanf("%d%s", &n, s);
    int ans, x;
    ans = x = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') x++;
        else x--;
        ans = max(ans, x);
    }
    printf("%d\n", ans);
    return 0;
}
