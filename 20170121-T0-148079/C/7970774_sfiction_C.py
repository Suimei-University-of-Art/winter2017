n = input()

a, b = map(int, raw_input().split()), [abs(x - (n - x - 1)) for x in xrange(n)]
a.sort()
b.sort()
if a != b:
	print '0'
	exit(0)

n >>= 1
s, e = 1, 2
MOD = 10 ** 9 + 7
while n > 0:
	if (n & 1) == 1:
		s = s * e % MOD
	e = e * e % MOD
	n >>= 1
print s
