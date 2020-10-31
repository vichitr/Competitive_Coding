for _ in range(input()):
	n=input()
	a=map(int,raw_input().split())
	flag=0
	for i in a:
		if i>n:
			flag=1
			break
	if flag==1:
		print "Ugly"
		continue
	flag=0
	b=[]
	for i in range(n-1):
		if a[i]<=a[i+1]:
			continue
		else:
			flag=1
			break
	if flag==0:
		print "Ugly"
	else:
		flag=0
		for i in a:
			if i in b:
				flag=1
				break
			else:
				b.append(i)
		if flag==1:
			print "Ugly"
		else:
			print "Beautiful"
