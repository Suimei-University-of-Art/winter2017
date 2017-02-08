#include <cstdio>

const int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leapYear(int x){
	return x % 4 == 0 && (x % 100 || x % 400 == 0);
}

int main(){
	int y, m, d;
	while (scanf("%d-%d-%d", &y, &m, &d) != EOF){
		int cnt = 0;
		for (int i = 2; i * 100 < y || i * 100 == y && (m > 2 || m == 2 && d == 29); ++i)
			cnt += !!(i & 3);
		while (cnt--)
			if (++d > day[m] + (m == 2 && leapYear(y)))
				if (d = 1, ++m > 12)
					m = 1, ++y;
		printf("%04d-%02d-%02d\n", y, m, d);
	}
	return 0;
}
