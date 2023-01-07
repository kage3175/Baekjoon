import sys
input=sys.stdin.readline

def count_smaller(number, n):
    cnt=0
    for i in range(1,n+1):
        cnt+=min(number//i,n)
    return cnt

n,k=map(int, input().split())

left=1
right=k

while(left<=right):
    mid=(left+right)//2
    if()