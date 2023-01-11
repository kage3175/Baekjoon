import sys
input=sys.stdin.readline

t=int(input())

for _ in range(t):
    size=int(input())
    start=list(map(int, input().split()))
    end=list(map(int, input().split()))
    queue1, queue2=[], []
    queue