t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    num_set = set(a)
    for num in a:
        if num > 0 and -num in num_set:
            num_set.remove(num)
        elif num < 0 and -num not in num_set:
            print(num)
