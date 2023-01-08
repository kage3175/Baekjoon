import sys
input=sys.stdin.readline

num=int(input())
lines=int(input())

network=[[] for _ in range(num+1)]
visited=[0 for _ in range(num+1)]
visited[1]=1
stack=[]

for i in range(lines):
    x,y=map(int, input().split())
    network[x].append(y)
    network[y].append(x)

start=1

for point in network[start]:
    stack.append(point)
    visited[point]=1

while stack:
    node=stack.pop()
    for point in network[node]:
        if visited[point]:#이미 방문한 경우
            continue
        else:
            visited[point]=1
            stack.append(point)

cnt=0

for i in range(num+1):
    if visited[i]:
        cnt+=1
print(cnt-1)