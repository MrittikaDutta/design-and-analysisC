t=int(input())
l=[]
for i in range(t):
    n=int(input())
    l1=[]
    for j in range(n):
        l1.append(j)
    for j in range(n):
        if j*-1 not in l1:
            l.append(j)
for a in l:
    print(a)