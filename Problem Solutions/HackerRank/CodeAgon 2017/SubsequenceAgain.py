s=raw_input()
k=input()
d={}
for i in s:
	if i in d:
		d[i]+=1
	else:
		d[i]=1
b=[]
for i in d:
	if d[i]>=k:
		b.append(i)
t=""
for i in s:
	if i in b:
		t+=i
print t
