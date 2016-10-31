u = [1, 1, 2, 2, 2, 4, 4, 5, 6, 4] # Edge set
v = [2, 3, 3, 3, 3, 5, 5, 6, 7, 7]

def getfa(x) :
	if (f[x] == x) :
		return x
	else:
		f[x] = getfa(f[x])
		return f[x]

if __name__ == '__main__' :
	answer = 0
	for mask in range(1, 1 << 10) : # Enumerate every possible edge sets.
		flag = 1
		number = 0
		f = [i for i in range(8)]
		for i in range(0, 10) :
			if (((mask >> i) & 1) == 1) :
				number = number + 1
				if (getfa(u[i]) == getfa(v[i])) :
					flag = 0
				else:
					f[getfa(u[i])] = getfa(v[i])
		if (number == 5 and flag) :
			answer = answer + 1
	print answer
