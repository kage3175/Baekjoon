import sys
input=sys.stdin.readline

s=input()
bomb=input()
s=s.replace('\n', '')
bomb=bomb.replace('\n', '')

list_s=list(s)
list_bomb=list(bomb)
idx=0
first=list_bomb.pop(0)
len_left=len(list_bomb)

def is_same(list_bomb, list_s, idx):
    global len_left
    flag=1
    for i in range(len_left):
        try:
            if list_bomb[i]!=list_s[i+idx]:
                flag=0
                break
        except IndexError:
            return 0
    return flag

while idx<len(list_s):
    #print(list_s)
    
    #print(list_s[idx], idx)
    if list_s[idx]==first:
        count=0
        while first==list_s[idx]:
            #print(list_s, first, idx, list_s[idx])
            idx+=1
            count+=1
            if idx>=len(list_s):
                break
        #print('x', idx)
        for i in range(count):
            if(is_same(list_bomb, list_s, idx)):
                del list_s[idx-1:idx+len_left]
                idx-=1
            else:
                break
        #print('y', idx)
    else:
        idx+=1
if list_s:
    for ch in list_s:
        print(ch, end='')
else:
    print('FRULA')

