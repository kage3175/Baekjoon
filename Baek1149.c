#include <stdio.h>
#include <stdlib.h>

int** cost;
int** sum_cost;
int n;

int min(int a, int b);

void sum(int depth);


int main(void){
	scanf("%d", &n);
	cost=(int**)malloc(sizeof(int*)*(n+1));
	cost[0]=(int*)malloc(sizeof(int)*3);
	for(int i=1;i<n+1;i++) cost[i]=cost[i-1]+3;
	sum_cost=(int**)malloc(sizeof(int*)*(n+1));
	sum_cost[0]=(int*)malloc(sizeof(int)*3);
	for(int i=1;i<n+1;i++) sum_cost[i]=sum_cost[i-1]+3;
	for(int i=1;i<n+1;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&sum_cost[i][j]);
		}
	}
	/*for(int i=0;i<n+1;i++){
		for(int j=0;j<3;j++){
			sum_cost[i][j]=0;
		}
	}*/
	/*for(int i=1;i<n+1;i++){
		for(int j=0;j<3;j++){
			scanf("%d", &cost[i][j]);
		}
	}*/
	printf("%d", cost[2][1]);
	free(cost[0]);
	free(cost);
	free(sum_cost[0]);
	free(sum_cost);
	return 0;
}

int min(int a, int b){
	if(a>b) return b;
	else return a;
}

void sum(int depth){//depth 1부터 시작 
	if(depth==0) return;
	sum_cost[depth][0]=min(sum_cost[depth-1][2], sum_cost[depth-1][1])+cost[depth][0];
	sum_cost[depth][1]=min(sum_cost[depth-1][2], sum_cost[depth-1][0])+cost[depth][1];
	sum_cost[depth][2]=min(sum_cost[depth-1][0], sum_cost[depth-1][1])+cost[depth][2];
	
}
