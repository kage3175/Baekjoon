#include <stdio.h>
#include <stdlib.h>

int m;int n;int map[501][501];int dp[501][501];
int dx[4]={-1,1,0,0};int dy[4]={0,0,-1,1};
int dfs(int x, int y);

int main(void){
	scanf("%d %d",&m, &n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d", &map[i][j]);
			dp[i][j]=-1;
		}
	}
	
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	
	printf("%d", dfs(1,1));
	
	return 0;
}

int dfs(int x, int y){
	//printf("%d %d\n", x, y);
	int newx;int newy;
	if(x==n&&y==m) return 1;
	if(dp[y][x]!=-1) return dp[y][x];
	dp[y][x]=0;
	for(int i=0;i<4;i++){
		newx=x+dx[i];
		newy=y+dy[i];
		if((newx>=1&&newx<=n)&&(newy>=1&&newy<=m)){
			//printf("!%d %d\n", newx, newy);
			if(map[y][x]>map[newy][newx]) dp[y][x]+=dfs(newx,newy);
		}
	}
	return dp[y][x];
}
