import sys
input=sys.stdin.readline

arr=[]

n=int(input())
result=0

arr=list(map(int, input().split()))
arr.sort()

for i in range(n):
    result+=(n-i)*arr[i]
    
print(result)