from itertools import permutations

n,m=map(int, input().split())
arr=[i+1 for i in range(n)]

answer=permutations(arr,m)

for per in answer:
    for i in range(m):
        print(per[i], end=" ")
    print("")