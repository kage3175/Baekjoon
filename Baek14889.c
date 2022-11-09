#include <stdio.h>
#include <stdlib.h>

int n;
int s[21][21]={0};
int which_team[21]={0};
int left[2]={0,0};
int min_diff=1000000001;

int score(int team_num);//team_numÀº 1¶Ç´Â 2 
void team_selection(int depth);

int main(void){
	int i=0;int j=0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++) scanf("%d", &s[i][j]);
	}
	left[0]=n/2;left[1]=n/2;
	
	team_selection(0);
	printf("%d", min_diff);
	
	return 0;
}

int score(int team_num){
	int score=0;
	for(int i=0;i<n;i++){
		if(which_team[i]==team_num){
			for(int j=i+1;j<n;j++){
				if(which_team[i]==which_team[j]){
					score+=s[i][j]+s[j][i];
				}
			}
		}
	}
	return score;
}

void team_selection(int depth){
	if(depth==n){
		if(abs(score(0)-score(1))<min_diff) min_diff=abs(score(0)-score(1));
	}
	for(int i=0;i<2;i++){
		if(left[i]>=1){
			left[i]-=1;
			which_team[depth]=i;
			team_selection(depth+1);
			left[i]+=1;
		}
	}
}


