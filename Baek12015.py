import sys
input=sys.stdin.readline

n=int(input())

arr=list(map(int, input().split()))
result=[0]
total_length=0

def binary_search(number):
    global result
    global arr
    global total_length
    left, right=0,total_length
    #print(number, result)
    while left<right:
        mid=(left+right)//2
        if(result[mid]>number):
            #print(1, left, right, mid, number, result)
            right=mid
            if(left==right):
                #print(number)
                if(result[left]>number):
                    result[left]=number
                return
        elif(result[mid]<number):
            #print(2, left, right,mid,number, result)
            left=mid+1
            if(left==right):
                #print(number)
                if(result[left]>number):
                    result[right]=number
                return
        else:
            return
        

for a in arr:
    #print(a, result)
    if result[total_length]<a:#추가
        result.append(a)
        total_length+=1
    else:#대치가 가능한가
        #print("들어간 수",a)
        binary_search(a)

print(total_length)