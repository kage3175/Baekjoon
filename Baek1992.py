import sys
from math import log
input=sys.stdin.readline

#depth 0 일 때는 n*n 사각형 전체를, 1일 때는 n/2*n/2를 본다
n=int(input())
size_total=int(log(n,2))
str_=''
depth=0
board=[[0 for i in range(n)] for _ in range(n)]
visited=[[] for _ in range(n)]

def make_str_(x,y,depth):
    global size_total
    global visited
    global str_
    global board
    size=n//(2**depth)
    now=board[x][y]
    if size==1:
        str_=str_+str(now)
        return 0
    flag=True
    for i in range(size):
        for j in range(size):
            if board[x+i][y+j]!=now:
                flag=False
                break
    if flag:
        str_=str_+str(now)
    else:
        str_=str_+'('
        make_str_(x,y,depth+1)
        make_str_(x,y+size//2,depth+1)
        make_str_(x+size//2,y,depth+1)
        make_str_(x+size//2,y+size//2,depth+1)
        str_=str_+')'

for i in range(n):
    tempstr=input()
    for j in range(n):
        board[i][j]=int(tempstr[j])
    
    
make_str_(0,0,0)
print(str_)