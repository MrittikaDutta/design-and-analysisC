t=int(input())
l=[]
for i in range(t):
    n=int(input())
    for j in range(2*n-1):
        s=input()
        d={}
        for b in s:
            if b.isdigit():
                if b in d:
                    d[b]+=1
                else:
                    d[b]=1
        for b in s:
            if d[b]==1:
                l.append(b)
            
p=set(l)
for a in l:
    print(a)