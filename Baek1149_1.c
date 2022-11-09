#include <stdio.h>
#include <stdlib.h>

int** cost;
int** sum_cost;
int n=0;

void solution(int depth);
int min(int a,int b);



int main(void){
	
	
	scanf("%d", &n);
	
	cost=(int**)malloc(sizeof(int*)*(n+1));
	sum_cost=(int**)malloc(sizeof(int*)*(n+1));
	for(int i=0;i<(n+1);i++) cost[i]=(int*)malloc(sizeof(int)*3);//arr[n][3];
	for(int i=0;i<(n+1);i++) sum_cost[i]=(int*)malloc(sizeof(int)*3);
	for(int i=1;i<(n+1);i++){
		for(int j=0;j<3;j++) scanf("%d",&cost[i][j]);
	}
	for(int i=0;i<(n+1);i++){
		for(int j=0;j<3;j++) sum_cost[i][j]=0;
	}
	/*for(int i=0;i<(n+1);i++){
		for(int j=0;j<3;j++) printf("%d ", sum_cost[i][j]);
	}*/
	
	solution(n);
	printf("%d", min(min(sum_cost[n][0],sum_cost[n][1]),sum_cost[n][2]));
	
	
	for(int i=0;i<(n+1);i++) free(cost[i]);
	free(cost);
	for(int i=0;i<(n+1);i++) free(sum_cost[i]);
	free(sum_cost);
	
	return 0;
}

int min(int a, int b){
	int x;
	x=a>b?b:a;
	return x;
}

void solution(int depth){
	if(depth==0) return;
	solution(depth-1);
	sum_cost[depth][0]=min(sum_cost[depth-1][1], sum_cost[depth-1][2])+cost[depth][0];
	sum_cost[depth][1]=min(sum_cost[depth-1][0], sum_cost[depth-1][2])+cost[depth][1];
	sum_cost[depth][2]=min(sum_cost[depth-1][1], sum_cost[depth-1][0])+cost[depth][2];
}
