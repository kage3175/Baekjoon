#include <stdio.h>
#include <stdlib.h>

int n;

int solution(int length);
long long* dfs;

int main(void){
	scanf("%d", &n);
	dfs=(long long*)malloc(sizeof(long long)*(n+1));
	for(int i=0;i<n+1;i++) dfs[i]=0;
	dfs[1]=1;
	dfs[2]=2;
	
	printf("%d\n", solution(n));
	
	return 0;
}

int solution(int length){
	if(dfs[length]!=0) return dfs[length];
	dfs[length]=(solution(length-1)+solution(length-2))%15746;
	return dfs[length];
}
