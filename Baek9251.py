import sys
input=sys.stdin.readline

str1=input().strip()
str2=input().strip()

dp=[[0 for i in range(len(str2)+1)] for _ in range(len(str1)+1)]

for i in range(len(str2)):
    for j in range(len(str1)):
        if str1[j]==str2[i]:
            dp[j+1][i+1]=dp[j][i]+1
        else:
            dp[j+1][i+1]=max(dp[j+1][i], dp[j][i+1])

print(dp[len(str1)][len(str2)])