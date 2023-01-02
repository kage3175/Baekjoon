#include <stdio.h>
#include <stdlib.h>

int weight_num;int weight[31];int ball_num;int ball[8];int dp[31][15001];

void is_okay(int x,int g);

int main(void){
	scanf("%d", &weight_num);
	for(int i=1;i<=weight_num;i++) scanf("%d", &weight[i]);
	scanf("%d", &ball_num);
	for(int i=1;i<=ball_num;i++) scanf("%d", &ball[i]);
	is_okay(0,0);
	/*for(int i=1;i<=weight_num;i++){
		for(int j=0;j<10;j++) printf("%d ", dp[i][j]);
		printf("\n");
	}*/
	for(int i=1;i<ball_num+1;i++){
		if(ball[i]>15000) printf("N\n");
		else if(dp[weight_num][ball[i]]) printf("Y\n");
		else printf("N\n");
	}
	
	
	return 0;
}

void is_okay(int x, int g){//x번째 추까지 있을 때 weight 무게가 가능한가 
	if(x>weight_num||dp[x][g]) return;
	dp[x][g] = 1;
	is_okay(x+1,g+weight[x+1]);
	is_okay(x+1,abs(g-weight[x+1]));
	is_okay(x+1, g);
}
