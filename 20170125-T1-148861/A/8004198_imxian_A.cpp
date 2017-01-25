#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", max(a * b, c * d));
    return 0;
}
