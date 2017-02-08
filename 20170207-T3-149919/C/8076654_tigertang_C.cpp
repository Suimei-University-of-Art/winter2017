#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if (x%y == 0) return y;
    return gcd(y,x%y);
}
int main()
{
    int x,y,z;
    while (scanf("%d%d%d",&x,&y,&z) > 0)
    {
        int u = x*y;
        int d = z-y;
        int g = gcd(u,d);
        u /= g;
        d /= g;
        printf("%d/%d\n",u,d);
    }
    return 0;
}
