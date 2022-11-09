import sys
input=sys.stdin.readline

n=int(input())

score=[]

score.append(0)

for i in range(n):
    score.append(int(input()))
    
dp=[[0 for i in range(3)] for _ in range(n+1)]

for i in range(3):
    dp[1][i]=score[1]
dp[2][1]=score[2]
dp[2][2]=score[2]
    
def max_value(num, cons):
    global n
    global score
    global dp
    if(num==0):
        return
    if()