import sys

def lowestTriangle(base, area):
    i = 1
    while i:
        if (i*base)/2>=area:
            break
        i+=1
    return i

base, area = raw_input().strip().split(' ')
base, area = [int(base), int(area)]
height = lowestTriangle(base, area)
print(height)
