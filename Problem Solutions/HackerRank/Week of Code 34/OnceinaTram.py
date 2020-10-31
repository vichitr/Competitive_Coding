import sys

def onceInATram(x):
    x=x+1
    t=x
    p=0
    q=0
    q+=t%10
    t=t/10
    q+=t%10
    t=t/10
    q+=t%10
    t=t/10
    p+=t%10
    t=t/10
    p+=t%10
    t=t/10
    p+=t
    
    while p!=q:
        x=x+1
        t=x
        p=0
        q=0
        for i in range(3):
            p+=(t%10)
            t=t/10
        for i in range(3):
            q+=(t%10)
            t=t/10
    return x

if __name__ == "__main__":
    x = int(raw_input().strip())
    result = onceInATram(x)
    print result
