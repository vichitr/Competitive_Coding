import os
import sys

# Complete the findTheAbsentStudents function below.
def findTheAbsentStudents(n, a):
    # Return the list of student IDs of the missing students in increasing order.
    f=[0]*n
    b=[]
    for i in a:
        f[i-1]=1
    for i in range(n):
        if f[i]==0:
            b.append(i+1)
    return b
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    a = list(map(int, input().rstrip().split()))

    result = findTheAbsentStudents(n, a)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
