#include <cstdio>
#include <algorithm>

using namespace std;

int a[8];
int b[10][10];

int tot;

void DFS(int x, int y){
	int i = b[x + 1][y] - 1;
	if (i > b[x][y + 1])
		i = b[x][y + 1];
	for (; i > x; --i){
		b[x][y] = i;
		if (y > 1)
			DFS(x, y - 1);
		else if (x > 1)
			DFS(x - 1, a[x - 1]);
		else
			++tot;
	}
	if (x == 1)
		++tot;
	else{
		for (; y > 0; --y)
			b[x][y] = x;
		DFS(x - 1, a[x - 1]);
	}
}

int main(){
	int K, n;
	while (scanf("%d", &K) != EOF){
		for (int i = 1; i <= K; ++i)
			scanf("%d", a + i);
		scanf("%d", &n);
		for (int i = 1; i <= K; ++i){
			b[i][a[i] + 1] = n + 1;
			for (int j = 1; j <= a[i]; ++j)
				b[i + 1][j] = n + 1;
		}
		tot = 0;
		DFS(K, a[K]);
		printf("%d\n", tot);
	}
	return 0;
}
