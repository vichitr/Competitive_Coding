import sys

def pythagoreanTriple(a):
    # Complete this function
    if a%2==0:
        k=a*a/4
        return a,k-1,k+1
    else:
        k=a*a/2
        return a,k,k+1

a = int(raw_input().strip())
triple = pythagoreanTriple(a)
print " ".join(map(str, triple))
