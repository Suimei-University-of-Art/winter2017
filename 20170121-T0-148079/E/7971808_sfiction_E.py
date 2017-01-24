n = input()
s = map(int, ('+ ' + raw_input()).replace('+ ', '+').replace('- ', '-').split())
s0 = [abs(x) for x in s]
t = filter(lambda x: s[x + 1] < 0, xrange(n - 1)) + [n - 1] * 2
for i in xrange(1, n):
	s[i] += s[i - 1]
	s0[i] += s0[i - 1]
print max([s0[n - 1] - 2 * s0[t[i + 1]] + s0[t[i]] + s[t[i]] for i in xrange(len(t) - 1)])
