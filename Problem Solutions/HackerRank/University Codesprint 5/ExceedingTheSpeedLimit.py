s=int(input())
if s<=90:
    print("0 No punishment")
elif s>90 and s<=110:
    print("%d Warning" %((s-90)*300))
else:
    print("%d License removed" %((s-90)*500))
