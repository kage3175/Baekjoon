import sys
input=sys.stdin.readline

n=int(input())

board=[[0]*(n+2) for _ in range(n+2)]
visited=[[0]*(n+2) for _ in range(n+2)]
cluster=[]
stack=[]
dx, dy=[1,-1,0,0], [0,0,1,-1]
cnt=0

for i in range(1, n+1):
    s=input().strip()
    for j in range(n):
        board[i][j+1]=int(s[j])

for i in range(1, n+1):
    for j in range(1, n+1):
        if board[i][j]==1 and visited[i][j]==0:#시작점
            stack.append((i,j))
            visited[i][j]=1
            cnt=1
            while stack:
                now=stack.pop()
                for k in range(4):
                    x,y=now[0]+dx[k], now[1]+dy[k]
                    #print(x,y)
                    if(board[x][y]==1 and visited[x][y]==0):
                        stack.append((x,y))
                        visited[x][y]=1
                        cnt+=1
            cluster.append(cnt)

cluster.sort()
print(len(cluster))
for num in cluster:
    print(num)