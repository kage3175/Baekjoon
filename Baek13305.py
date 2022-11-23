import sys
input=sys.stdin.readline

fuel_tank=0
total_price=0
i=0
now=0

n=int(input())
dist=list(map(int, input().split()))
price=list(map(int, input().split()))
price[n-1]=0

while i<n-1:
    fuel_tank=dist[i]
    now=i
    while 1:
        if price[now]<price[i+1]:
            if i+1<n:
                fuel_tank+=dist[i+1]
            i+=1
        else:
            i+=1
            break
    total_price+=fuel_tank*price[now]

print(total_price)