def gcd(a, b):
	return a if b == 0 else gcd(b, a % b)

while True:
	try:
		a, b, c = map(int, input().split())
	except:
		break

	a, b = a * b, c - b
	d = gcd(a, b)
	print('%d/%d' %(a / d, b / d))
