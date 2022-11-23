import sys
input=sys.stdin.readline

n=int(input())

stack=[]

for i in range(n):
    order=input().split()
    if order[0]=='push':
        stack.append(int(order[1]))
    elif order[0]=='top':
        if len(stack):
            print(stack[-1])
        else:
            print(-1)
    elif order[0]=='pop':
        if len(stack):
            print(stack.pop())
        else :
            print(-1)
    elif order[0]=='size':
        print(len(stack))
    else :
        if len(stack):
            print(0)
        else:
            print(1)