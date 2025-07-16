t=int(input())
l=[]

for i in range(t):
    n=int(input())
    a=input()
    a=a.split()
    # for j in range(n):
    #     l1.append(a[j])
    for j in range(n):
        if a[j]*-1 not in a:
            l.append(int(a[j]))
# for h in l:
#     print(h)
for h in l:
    f=int(h)*-1
    if f in l:
        l.remove(f)
        l.remove(h)
    if int(h)==0:
        l.remove(h)
for h in l:
    f=int(h)*-1
    if f not in l:
        print(h)   
    