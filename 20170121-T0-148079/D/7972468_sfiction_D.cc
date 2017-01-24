#include <cstdio>

typedef long long ll;

const ll MOD = 1E9 + 7, MAXD = 60;

ll n;
ll f[MAXD + 1][3];

int main(){
	scanf("%lld", &n);

	f[MAXD][0] = 1;
	for (int i = MAXD - 1; i >= 0; --i){
		int z = n >> i & 1;
		if (z == 0){
			f[i][0] = (f[i + 1][0] + f[i + 1][1]) % MOD;
			f[i][1] = (f[i + 1][1]) % MOD;
			f[i][2] = (f[i + 1][1] + f[i + 1][2] * 3) % MOD;
		}
		else{
			f[i][0] = (f[i + 1][0]) % MOD;
			f[i][1] = (f[i + 1][0] + f[i + 1][1]) % MOD;
			f[i][2] = (f[i + 1][1] * 2 + f[i + 1][2] * 3) % MOD;
		}
	}

	printf("%lld\n", (f[0][0] + f[0][1] + f[0][2]) % MOD);
	return 0;
}
