import sys
import heapq
input=sys.stdin.readline

heap=[]

n=int(input())

for i in range(n):
    key=int(input())
    if(key):#입력이 0이 아닌 경우
        heapq.heappush(heap, (abs(key), key))
    else:
        if not heap:
            print(0)
        else:
            print(heapq.heappop(heap)[1])