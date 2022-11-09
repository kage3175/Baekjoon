import sys
input=sys.stdin.readline

dynamic=[[[-1 for _ in range(21)] for i in range(21)] for j in range(21)]

for i in range(21):
    for j in range(21):
        dynamic[0][i][j],dynamic[i][j][0], dynamic[i][0][j]=1,1,1

def w(a,b,c):
    global dynamic
    if a<=0 or b<=0 or c<=0 :
        return 1
    if a>20 or b>20 or c>20:
        return w(20,20,20)
    if dynamic[a][b][c]!=-1:
        return dynamic[a][b][c]
    if a<b<c:
        dynamic[a][b][c]=w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c)
        return dynamic[a][b][c]
    else:
        dynamic[a][b][c]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
        return dynamic[a][b][c]    
    
a,b,c=map(int, input().split())

while True:
    print('w(%d, %d, %d) = %d'%(a,b,c,w(a,b,c)))
    a,b,c=map(int, input().split())
    if(a==-1 and b==-1 and c==-1):
        break