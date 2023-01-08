import sys
input=sys.stdin.readline

n, m, v = map(int, input().split())

lines=[[] for _ in range(n+1)]
visited=[0 for _ in range(n+1)]
stack=[]

for i in range(m):
    x, y = map(int, input().split())
    lines[x].append(y)
    lines[y].append(x)

for i in range(1,n+1):
    lines[i].sort(reverse=True)

for point in lines[v]:
    stack.append(point)

visited[v]=1
print(v, end=' ')

while stack: #DFS
    node = stack.pop()
    if visited[node]==0:
        print(node, end=' ')
        visited[node]=1
    for point in lines[node]:
        if visited[point]:
            continue
        else:
            stack.append(point)

visited=[0 for _ in range(n+1)]
stack=[]
visited[v]=1
print(v, end=' ')

