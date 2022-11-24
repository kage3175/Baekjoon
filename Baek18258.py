import sys
input=sys.stdin.readline

n, *args=open(0).read().split("\n")
arr=[]
for i in range(n):
    indicator=args[i][:3]
    if(indicator=="pus"):
        temp=list(args[i].split())
        arr.append(int(temp[1]))
    elif indicator=="pop":
        if(len(arr)):
            print(arr.pop(0))
        else:
            print(-1)
    elif indicator=="siz":
        print(len(arr))
    elif indicator=="emp":
        if(len(arr)==0):
            print(1)
        else:
            print(0)
    elif indicator=="fro":
        if(len(arr)):
            print(arr[0])
        else:
            print(-1)
    else:
        if(len(arr)):
            print(arr[-1])
        else:
            print(-1)
            