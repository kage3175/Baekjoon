import sys
input=sys.stdin.readline

#n,*args=open(0).read().split()

#args=map(int, args)

n=int(input())

triangle=[]

for i in range(n):
    triangle.append(list(map(int, input().split())))
    
'''for i in range(n):
    print(triangle[i])'''

dp=[]

for i in range(n):
    dp.append([-1 for _ in range(i+1)])

def dp_cycle(nth,depth):
    global triangle
    global n
    global dp
    if depth==0 :
        dp[depth][0]=triangle[depth][0]
        return 0
    if nth!=0 and nth!=depth:
        if dp[depth-1][nth]==-1:
            dp_cycle(nth, depth-1)
        if dp[depth-1][nth-1]==-1:
            dp_cycle(nth-1, depth-1)
        dp[depth][nth]=max(dp[depth-1][nth], dp[depth-1][nth-1])+triangle[depth][nth]
    elif nth==0:
        if dp[depth-1][nth]==-1:
            dp_cycle(nth, depth-1)
        dp[depth][nth]=dp[depth-1][nth]+triangle[depth][nth]
    elif nth==depth:
        if dp[depth-1][nth-1]==-1:
            dp_cycle(nth-1, depth-1)
        dp[depth][nth]=dp[depth-1][nth-1]+triangle[depth][nth]
        
for i in range(n): 
    dp_cycle(i,n-1)
    
print(max(dp[n-1]))