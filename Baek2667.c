#include <stdio.h>
#include <stdlib.h>

int board[26][26];
int n;int cluster[314];

int main(void){
	char ch;char trash;
	scanf("%d", &n);
	trash=getchar();
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			board[i][j]=getchar()-'0';
		}
		trash=getchar();
	}
	
	/*for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}*/
	
	return 0;
}
