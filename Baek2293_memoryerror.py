import sys
input=sys.stdin.readline

n, k=map(int, input().split())
coins=[0]*(n+1)

for i in range(1,n+1):
    coins[i]=int(input())


dp=[[0]*(k+1) for _ in range(n+1)]#dp[x][y] x번째 동전까지 있을 때 y를 만드는 방법의 수
#print(coins, dp)
for i in range(k//coins[1]+1):
    #print(i*coins[1])
    dp[1][i*coins[1]]=1

for i in range(2, n+1):
    for j in range(0,k+1):
        if(j<coins[i]):
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]]

print(dp[n][k])