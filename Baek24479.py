import sys
input=sys.stdin.readline

n, m, r=map(int, input().split())

lines=[[] for i in range(n+1)]

for i in range(m):
    s, a=map(int, input().split())
    lines[s].append(a)
    lines[a].append(s)

for i in range(n+1):
    lines[i].sort()

