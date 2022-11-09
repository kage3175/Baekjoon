

n=int(input())

score=[]

score.append(0)

for i in range(n):
    score.append(int(input()))
    
dp=[[-1 for i in range(3)] for _ in range(n+1)]

for i in range(3):
    dp[0][i]=0
    dp[1][i]=score[1]
if(n>=2):
    dp[2][1]=score[2]
    dp[2][2]=score[2]
    
def max_value(num, cons):
    global n
    global score
    global dp
    if(num==0 or num==1):
        return 0
    if(cons==1):
        if dp[num-2][0]==-1:
            max_value(num-2,0)
        dp[num][cons]=score[num]+dp[num-2][0]
    else:
        if dp[num-1][cons+1]==-1:
            max_value(num-1, cons+1)
        if dp[num-2][0]==-1:
            max_value(num-2,0)
        dp[num][cons]=score[num]+max(dp[num-1][cons+1], dp[num-2][0])
        
max_value(n,0)

print(dp[n][0])