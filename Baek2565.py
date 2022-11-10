import sys
input=sys.stdin.readline

n=int(input())
a=[[0,0]]
maxv=1
arr=[0 for i in range(n+1)]
dp=[1 for i in range(n+1)]
for i in range(n):
    a.append(list(map(int, input().split())))    

a.sort(key=lambda x:x[0])

for i in range(1,n+1):
    arr[i]=a[i][1]


for i in range(2,n+1):
    for j in range(1,i):
        if arr[i]>arr[j]:
            if dp[i]<dp[j]+1:
                dp[i]=dp[j]+1
                if dp[i]>maxv:
                    maxv=dp[i]
                    
print(n-maxv)
                