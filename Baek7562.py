import sys
input=sys.stdin.readline

move=[(1,2), (2,1), (2,-1),(1,-2),(-1,-2),(-2,-1,),(-2,1),(-1,2)]

t=int(input())

for _ in range(t):
    depth=0
    flag=0
    size=int(input())
    start=tuple(map(int, input().split()))
    end=tuple(map(int, input().split()))
    queue1, queue2=[], []
    visited=[[0]*(size+2) for i in range(size+2)]
    queue1.append(start)
    visited[start[0]][start[1]]=1
    while(queue1 or queue2):
        depth+=1
        while(queue1):
            node=queue1.pop()
            if(node[0]==end[0] and node[1]==end[1]):
                flag=1
                break
            for tup in move:
                x,y=tup[0]+node[0], tup[1]+node[1]
                if 0<=x<size and 0<=y<size and visited[x][y]==0:
                    queue2.append((x,y))
                    visited[x][y]=1
                    '''if(x==end[0] and y==end[1]):
                        flag=1
                        break'''
        if(flag):
            break
        depth+=1
        while(queue2):
            node=queue2.pop()
            if(node[0]==end[0] and node[1]==end[1]):
                flag=1
                break
            for tup in move:
                x,y=tup[0]+node[0], tup[1]+node[1]
                if 0<=x<size and 0<=y<size and visited[x][y]==0:
                    queue1.append((x,y))
                    visited[x][y]=1
                    '''if(x==end[0] and y==end[1]):
                        flag=1
                        break'''
        if(flag):
            break
        
    print(depth-1)