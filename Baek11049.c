#include <stdio.h>
#include <stdlib.h>

#define INF 2147483646
#define min(x,y) ((x)>(y))?(y):(x)

int dp[501][501];

int main(void){
	int n;int r[501];int c[501];
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d %d", &r[i], &c[i]);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			dp[j][i+j]=INF;
			for(int k=j;k<i+j;k++){
				dp[j][i+j]=min(dp[j][i+j], dp[j][k]+dp[k+1][i+j]+r[j]*c[k]*c[i+j]);//c[k]==r[k+1]
				//printf("%d %d %d\n", j, i+j, dp[j][i+j]);
			}
		}
	}
	
	printf("%d", dp[1][n]);
	
	return 0;
}
