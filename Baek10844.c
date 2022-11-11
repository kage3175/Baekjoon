#include <stdio.h>
#include <stdlib.h>

#define DIVIDE 1000000000

int dp[101][9]={0};//dp[n][0]은 n번째 계단수 중 첫 자리가 1인 것의 개수, [1]는 2 ..... 
int n;

int main(void){
	long long sum=0;
	scanf("%d",&n);
	for(int i=0;i<9;i++) dp[1][i]=1;
	dp[0][0]=1;
	for(int i=2;i<n+1;i++){
		dp[i][0]=(dp[i-1][1]+dp[i-2][0])%DIVIDE;
		for(int j=1;j<8;j++){
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%DIVIDE;
		}
		dp[i][8]=dp[i-1][7]%DIVIDE;
	}
	for(int i=0;i<9;i++) sum=(sum+dp[n][i])%DIVIDE;
	printf("%lld", sum);
	return 0;
}
