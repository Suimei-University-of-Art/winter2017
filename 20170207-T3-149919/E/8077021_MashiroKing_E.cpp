#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int ps, sz;

int f[2][MAXN];
int L[MAXN], R[MAXN];
char s[MAXN];

void dfs(int x){
	ps++;
	if (s[ps] == '('){
		L[x] = ++sz;
		dfs(sz);
		R[x] = ++sz;
		dfs(sz);
		ps++;
	}
	else if (s[ps] == ')'){
		L[x] = R[x] = 0;
		ps++;
	} else if (s[ps] == 'B'){
		L[x] = R[x] = -1;
		ps+=2; m++;
	}
}

void work(int x, int bell){
	if (f[bell & 1][x] != -2) return ;
	if (L[x] > 0){
		int tmp = bell/2;
		if (bell & 1){
			int nico, maki;
			work(L[x], bell / 2);
			work(R[x], bell / 2 + 1);
			if (f[tmp&1][L[x]] == -1 || f[1-(tmp&1)][R[x]] == -1)
				nico = -1;
			else
				nico = f[tmp&1][L[x]] + f[1-(tmp&1)][R[x]];
			work(L[x], bell / 2 + 1);
			work(R[x], bell / 2);
			if (f[1-(tmp&1)][L[x]] == -1 || f[tmp&1][R[x]] == -1)
				maki = -1;
			else
				maki = f[1-(tmp&1)][L[x]] + f[tmp&1][R[x]];
			if (nico == -1) f[bell&1][x]=maki;
			else if (maki == -1) f[bell&1][x]=nico;
			else f[bell&1][x] = min(nico, maki);
		}
		else{
			work(L[x], tmp);
			work(R[x], tmp);
			if (f[tmp&1][L[x]] == -1 || f[tmp&1][R[x]] == -1)
				f[bell & 1][x] = -1;
			else
				f[bell&1][x] = f[tmp&1][L[x]] + f[tmp&1][R[x]];
		}
	}
	else{
		if (bell > 1) {
			f[bell & 1][x] = -1;
		}
		else
			f[bell & 1][x] = (bell != -L[x]);
	}
}

void solve(int casi){
	sz = 1, ps = 0, m = 0;
	dfs(1);
	for(int i = 1; i <= sz; i++)
		f[0][i] = f[1][i] = -2;
	work(1, m);
/*	cout<<m<<endl;
	for(int i = 1; i <= sz; i++){
		cout<<L[i]<<' '<<R[i]<<' '<<f[0][i]<<' '<<f[1][i]<<endl;
	}
*/	if (f[m&1][1]==-1)puts("impossible");
	else printf("%d\n", f[m&1][1] / 2);
}

void printans(){

}


int main(){
	while(scanf("%s", s) != EOF){
		solve(0);
	}
	return 0;
}


