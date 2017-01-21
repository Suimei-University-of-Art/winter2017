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

int a[MAXN];

ll calc(int p){
	ll ret = 1;
	for(int i = 1; i <= p; i++)
		ret = ret * 2 % MM;
	return ret;
}

void solve(int casi){
	cin>>n;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if (n & 1){	
		for(int i = 1; i <= n; i++){
			if (a[i] != i / 2 * 2){
				puts("0");
				return ;
			}
		}
		cout<<calc(n/2)<<endl;
	}
	else{
		for(int i = 1; i <= n; i++){
			if (a[i] != (i + 1) / 2 * 2 - 1){
				puts("0");
				return ;
			}
		}
		cout<<calc(n/2)<<endl;
	}
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


