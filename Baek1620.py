n,m, *args=open(0).read().split()
n=int(n)
m=int(m)

dict={}

for i in range(n):
    dict[args[i]]=str(i+1)
    dict[str(i+1)]=args[i]
    
for i in range(m):
    print(dict[args[i+n]])