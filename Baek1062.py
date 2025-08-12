from itertools import combinations
import sys

def check(s: str, alphabets):
  for c in s:
    if not alphabets[ord(c) - 97]:
      return False
  return True

def main():
  alphabets = [False for i in range(26)]
  whitelist = [0, 2, 13, 19, 8]
  alllist = [i for i in range(26)]
  for i in whitelist:
    alphabets[i] = True
  ####
  strings = []
  
  n, k = map(int, sys.stdin.readline().split())
  for i in range(n):
    strings.append(sys.stdin.readline().rstrip())
  ##### End of for loop
  
  if(k < 5):
    print(0)
    return
  ######
  elif(k >= 26):
    print(n)
    return
  ######
  
  target = [x for x in alllist if x not in whitelist]
  
  maxAvailable = 0
  
  for i in combinations(target, k-5):
    cnt = 0
    alphabets = [False for i in range(26)]
    for j in whitelist:
      alphabets[j] = True
    for j in i:
      alphabets[j] = True
    for s in strings:
      if(check(s, alphabets)):
        cnt += 1
    if(cnt > maxAvailable):
      maxAvailable = cnt
  ######
  
  print(maxAvailable)
############################## End of main
  

main()