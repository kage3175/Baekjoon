#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n=0;int flag=0;
	int arr[1001]={0};
	int dp[1001]={0};
	int max=1;
	scanf("%d", &n);
	for(int i=1;i<n+1;i++) scanf("%d", &arr[i]);
	dp[1]=1;
	for(int i=2;i<n+1;i++){
		flag=0;
		for(int j=1;j<i;j++){
			if(arr[i]>arr[j]){
				flag=1;
				if(dp[i]<dp[j]+1) dp[i]=dp[j]+1;
			}
		}
		if(flag==0) dp[i]=1;
		if(dp[i]>max) {
			max=dp[i];
		}
	}
	
	printf("%d", max);
	
	
	return 0;
}
