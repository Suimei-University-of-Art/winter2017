#include <cstdio>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAXN = 1E2 + 10;

int a[MAXN];
double f[MAXN * 11];

int main(){
	char s[10];
	int n;
	while (scanf("%d%d", &n, a + 1) != EOF){
		for (int i = 2; i <= n + 1; ++i){
			s[1] = s[2] = '\0';
			scanf("%s", s);
			if (s[0] <= '9')
				sscanf(s, "%d", a + i);
			else
				a[i] = 10 + (s[0] == 'A');
			a[i] += a[i - 1];
		}

		int m = a[n];
		for (int i = 1; i <= n; ++i)
			f[a[i]] = -2;
		fill_n(f + m + 1, 12, 0.0);
		double s = 0.0;
		for (int i = m; i >= 1; --i){
			s += f[i + 2] - f[i + 12];
			if (f[i] < -1){
				f[i] = 1.0;
				continue;
			}
			f[i] = (s + 3 * f[i + 10]) / 13.;
		}
		printf("%.12f\n", accumulate(f + 1, f + 11, 0.0) / 10.0);
	}
	return 0;
}
