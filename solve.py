N1 = ...
e1 = ...
ct1 = ...

N2 = ...
e2 = ...
ct2 = ...

from Crypto.Util.number import inverse, long_to_bytes, bytes_to_long
from gmpy2 import mul,gcd

def ProductTree(s):
    l = len(s)
    while l > 1:
        if l & 1 != 0:
            s += [1]
            l += 1
        s = list(map(mul, s[0 : l >> 1], s[l >> 1 :]))
        l = len(s)
    return s[0]

def Find_factor(pubs):
	priv_keys = []
	M = ProductTree(pubs)

	for i in range(0, len(pubs) - 1):
		pub = pubs[i]
		R = M // pub
		g = gcd(pub, R)
		if pub > g > 1:
			try:
				p = g
				q = pub // g
				return p,q
			except Exception as ex:
				print(ex)
				continue

p1,q1 = Find_factor([N1,N2])
p2,q2 = Find_factor([N2,N1])

n1 = p1*q1
n2 = p2*q2

phi1 = (p1-1) * (q1-1)
phi2 = (p2-1) * (q2-1)


d1 = inverse(e1, phi1)
d2 = inverse(e2, phi2)

m1 = pow(ct1, d1, n1)
m2 = pow(ct2, d2, n2)

print(long_to_bytes(m1)+long_to_bytes(m2))
