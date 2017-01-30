#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 3e5 + 10;

int n, m;

class BITree{
public:
    static const int SIZE = 100010, BIAS = 5;
    int u[SIZE];
    void clear(){
        memset(u,0,sizeof(u));
    }
    void modify(int x, int v){
        for(x+=BIAS;x<SIZE;x+=x&-x) u[x]+=v;
    }
    int getsum(int x){
        int s=0;
        for(x+=BIAS;x;x-=x&-x) s+=u[x];
        return s;
    }
} honoka;

int ans[MAXN];
vector<int> E[MAXN];
vector<PII> F[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[y].emplace_back(x);
	}
	ans[1] = 0;
	for(int i = 2; i <= m; i++){
		ans[i] = 0;
		for(int j = 0; j < m; j += i){
			F[min(j+i-1,m)].emplace_back(PII(i,j+1));
		}
	}
	for(int i = 0; i <= m; i++){
		for(int j = 0; j < E[i].size(); j++)
			honoka.modify(E[i][j]+1, -1),honoka.modify(-1, 1);
		for(int j = 0; j < F[i].size(); j++)
			ans[F[i][j].first] += honoka.getsum(F[i][j].second);
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", n - ans[i]);
	return 0;
}
