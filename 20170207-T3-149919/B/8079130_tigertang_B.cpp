#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
int n,ans,adj[500][500],w[500];
void dfs(vector<int> &c,int tmp)
{
    ans = tmp>ans?tmp:ans;
    int m = c.size();
    for (int i = 1;i <= n;i++)
    {
        int j;
        for (j = 0;j < m;j++)
            if (!adj[i][c[j]])
                break;
        if (j != m) continue;
        c.push_back(i);
        dfs(c,tmp+w[i]);
        c.erase(c.end()-1);
    }
}
int main()
{
    int m;
    while (cin >> n >> m)
    {
        memset(adj,0,sizeof(adj));
        ans = 0;
        for (int i = 1;i <= n;i++) scanf("%d",&w[i]);
        while (m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            adj[x][y] = adj[y][x] = 1;
        }
        vector<int> c;
        dfs(c,0);
        cout << ans << endl;
    }
    return 0;
}
