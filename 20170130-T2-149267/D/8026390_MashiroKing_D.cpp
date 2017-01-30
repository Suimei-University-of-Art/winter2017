#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

vector<PIP> E;

class BITree{
public:
    static const int SIZE = 100010, BIAS = 5;
    long long u[SIZE];
    void clear(){
        memset(u,0,sizeof(u));
    }
    void modify(int x, long long v){
        for(x+=BIAS;x<SIZE;x+=x&-x) u[x]+=v;
    }
    long long getsum(int x){
        long long s=0;
        for(x+=BIAS;x;x-=x&-x) s+=u[x];
        return s;
    }
} honoka;

int ans[MAXN];

void solve(int casi){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E.push_back(PIP(y, PII(-1, x)));
	}
	ans[1] = 0;
	for(int i = 2; i <= m; i++){
		ans[i] = 0;
		for(int j = 0; j < m; j += i){
			E.push_back(PIP(min(j + i - 1, m), PII(i, j + 1)));
		}
	}
	sort(E.begin(), E.end());
	for(int i = 0; i < E.size(); i++){
		if (E[i].second.first < 0){
			honoka.modify(-1, 1);
			honoka.modify(E[i].second.second+1, -1);
		}
		else{
			ans[E[i].second.first] += honoka.getsum(E[i].second.second);
		}
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", n - ans[i]);
}

void printans(){

}


int main(){
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}


