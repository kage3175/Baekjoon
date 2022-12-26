import sys
input=sys.stdin.readline

size=0
arr=[]

def binary_search(num):
    global arr
    global size
    left, right=0,size-1
    if(left==right):
        if(arr[left]>num):
            arr.insert(0,num)
        else:
            arr.insert(1,num)
        size+=1
        return
    while(left<right):
        mid=(left+right)//2
        if(arr[mid]>num):
            right=mid
        elif(arr[mid]<num):
            left=mid+1
        else:
            arr.insert(left,num)
        if(left==right):
            if(arr[left]>num):
                arr.insert(left, num)
            else:
                arr.insert(left+1, num)
            size+=1
    
n=int(input())
for i in range(n):
    key=int(input())
    if(key==0):
        if(size==0):
            print(0)
        else:
            print(arr.pop())
            size-=1
    else:
        if(size==0):
            arr.append(key)
            size=1
        else:
            binary_search(key)
