import sys
input=sys.stdin.readline

n,m=map(int, input().split())

board=[[0]*(m+2) for _ in range(n+2)] #1,1부터 4,6까지
visited=[[0]*(m+2) for _ in range(n+2)]
dx, dy=[1,-1,0,0], [0,0,1,-1]
cnt=0
queue1=[]
queue2=[]
dist=0
flag=0

for i in range(1, n+1):
    s=input().strip()
    for j in range(m):
        board[i][j+1]=int(s[j])

queue1.append((1,1))
dist+=1
visited[1][1]=1

while queue1 or queue2:
    if queue1: #queue2가 빈 경우
        dist+=1
        while queue1:
            node=queue1.pop(0)
            #print(node, dist)
            for i in range(4):
                x,y=node[0]+dx[i], node[1]+dy[i]
                if x==n and y==m:
                    flag=1
                    break
                if board[x][y]==1 and visited[x][y]==0:
                    queue2.append((x,y))
                    visited[x][y]=1
            if flag:
                break
    elif queue2:
        dist+=1
        while queue2:
            node=queue2.pop(0)
            #print(node, dist)
            for i in range(4):
                x,y=node[0]+dx[i], node[1]+dy[i]
                if x==n and y==m:
                    flag=1
                    break
                if board[x][y]==1 and visited[x][y]==0:
                    queue1.append((x,y))
                    visited[x][y]=1
            if flag:
                break
    else:
        print("???")
        sys.exit(1)
    if flag:
        break
    
print(dist)
                    