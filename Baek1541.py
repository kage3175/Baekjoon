import sys
input=sys.stdin.readline

arr=input().split("-")
formula=[]
cnt=0
result=0

for num_and_plus in arr:
    formula.append(list(map(int,num_and_plus.split("+"))))
    
for num_list in formula:
    if cnt==0:
        result+=sum(num_list)
    else:
        result-=sum(num_list)
    cnt+=1
    
print(result)