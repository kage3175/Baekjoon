#include <stdio.h>
#include <stdlib.h>

int dp[101]={0};
int ladder[16][2];int snake[16][2];

int is_snake(int num, int size);//ÇöÀç Å½»öÁßÀÎ Ä­ÀÌ ¹ì Ãâ¹ßÄ­ÀÎÁö È®ÀÎ 
int is_ladder(int num, int size);//ÇöÀç Å½»öÁßÀÎ Ä­ÀÌ »ç´Ù¸® µµÂøÄ­ÀÎÁö È®ÀÎ 

int main(void){
	int n, m;int x;
	
	
	scanf("%d %d", &n, &m);
	
	for(int i=0;i<n;i++) scanf("%d %d", &ladder[i][0], &ladder[i][1]);
	for(int i=0;i<m;i++) scanf("%d %d", &snake[i][0], &snake[i][1]);
	
	for(int i=1;i<=100;i++){
		if(i<=6){
			dp[i]=1;
			continue;
		}
		else{
			dp[i]=100000;
			for(int j=1;j<=6;j++){
				if(!is_snake(i-j, m)){
					if(dp[i]>dp[i-j]+1) dp[i]=dp[i-j]+1;
				}
			}
			if((x=is_ladder(i,n))!=-1){
				if(dp[i]>dp[ladder[x][0]]+1) dp[i]=dp[ladder[x][0]];
			}
		}
	}
	printf("%d", dp[100]);
	
	return 0;
}

int is_snake(int num, int size){
	for(int i=0;i<size;i++){
		if(num==snake[i][0]) return 1;
	}
	return 0;
}

int is_ladder(int num, int size){
	for(int i=0;i<size;i++){
		if(num==ladder[i][1]) return i;
	}
	return -1;
}
