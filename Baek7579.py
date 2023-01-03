import sys
import heapq
input=sys.stdin.readline
sys.setrecursionlimit(10**6)

heap=[]
n, m=map(int, input().split())
memory=list(map(int, input().split()))
cost=list(map(int, input().split()))
max_cost=sum(cost)
answer=-1
size=n

for pair in zip(cost, memory):
    heapq.heappush(heap, pair)
    
while(1):
    if(not heap[0][0]): #heap의 제일 작은 cost 값이 0일 경우
        m-=heap[0][1]
        size-=1
        if m<=0:
            answer=0
        heapq.heappop(heap)
    else:
        break

heap.sort(key= lambda x:(x[0], -x[1]))

dp=[[0]*(max_cost+1) for _ in range(size)]#dp[i][j]는 i번째까지 썼을 때 j의 비용으로 얻을 수 있는 최대 메모리

for i in range(heap[0][0], max_cost+1):
    dp[0][i]=heap[0][1]

for i in range(1,size):
    for j in range(max_cost+1):
        if(j>=heap[i][0]):
            dp[i][j]=max(dp[i][j], dp[i-1][j-heap[i][0]]+heap[i][1])
        dp[i][j]=max(dp[i][j], dp[i-1][j])

#print(dp)

if(answer==0):
    print(0)

else:
    for memories in dp[-1]:
        answer+=1
        if memories>=m:
            print(answer)
            break
        

#print(heap, m, answer)