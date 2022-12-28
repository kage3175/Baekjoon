#include <stdio.h>
#include <stdlib.h>

#define INF 2147483646
#define min(x,y) ((x)>(y))?(y):(x)

int dp[501][501];int cost[501];int sum[501];

int main(void){
	int T;int K;
	scanf("%d", &T);
	
	for(int m;m<T;m++){
		sum[0]=0;
		scanf("%d", &K);
		for(int i=1;i<=K;i++){
			scanf("%d", &cost[i]);
			sum[i]=sum[i-1]+cost[i];
		}
		for(int i=1;i<=K;i++){
			for(int j=1;j<=K-i;j++){
				dp[j][i+j]=INF;
				for(int x=j;x<i+j;x++){
					dp[j][i+j]=min(dp[j][i+j], dp[j][x]+dp[x+1][i+j]+sum[i+j]-sum[j-1]);
				}
			}
		}
		printf("%d\n", dp[1][K]);
	}
	
	return 0;
}
