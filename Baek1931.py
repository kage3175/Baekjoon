import sys
input=sys.stdin.readline

arr=[]

#n, *args=open(0).read().split()
n=int(input())
for i in range(n):
    arr.append(list(map(int, input().split())))
now=0
cnt=0

'''for i in range(n):
    arr.append(list(map(int, args[i].split())))'''
    
arr.sort(key= lambda x:(x[1], x[0]))
for time_ in arr:
    if time_[0]>=now:
        now=time_[1]
        cnt+=1
    elif time_[0]==time_[1]:
        cnt+=1
        now=time_[1]
        
print(cnt)