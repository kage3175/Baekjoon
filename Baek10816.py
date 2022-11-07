n=int(input())
list_card=list(map(int, input().split()))
m=int(input())
goal=list(map(int,input().split()))

dict={}

for card in list_card:
    try:
        dict[card]+=1
    except KeyError:
        dict[card]=1
        
for i in range(m):
    try:
        print(dict[goal[i]],end=" ")
    except KeyError:
        print(0,end=" ")