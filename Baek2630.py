import sys
from math import log
input=sys.stdin.readline

n=int(input())
k=log(n, 2)
cnt_white=0
cnt_blue=0
flag=True
board=[[] for _ in range(n)]
visited=[[0 for _ in range(n)] for i in range(n)]

for i in range(n):
    board[i]=list(map(int, input().split()))
    
#print(int(k))
for i in range(int(k),-1,-1):
    x=0
    flag=True
    side=2**(i)
    #print(side)
    while x<n:
        y=0
        while y<n:
            if visited[x][y]==0:
                x1=x
                now=board[x][y]
                while x1<x+side:
                    y1=y
                    while y1<y+side:
                        if board[x1][y1]!=now or visited[x1][y1]:
                            flag=False
                            break
                        y1+=1
                    if flag==False:
                        break
                    x1+=1
                if flag:
                    if now==1:
                        cnt_blue+=1
                    else:
                        cnt_white+=1
                    for j in range(side):
                        for k in range(side):
                            visited[x+j][y+k]=1
                else:
                    flag=True
            y+=side
        x+=side
                    
print(cnt_white)
print(cnt_blue)
                    
                            