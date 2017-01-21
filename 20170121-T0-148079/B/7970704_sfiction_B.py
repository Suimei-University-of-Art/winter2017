n = input()
a = map(int, raw_input().split())
s = sum(a)
m = input()
for i in xrange(m):
	p, x = map(int, raw_input().split())
	p -= 1
	print s - a[p] + x
