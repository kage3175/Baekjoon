#include <stdio.h>
#include <stdlib.h>

int board[9][9]={0};

int check_row(int what_row, int x);
int check_col(int what_col, int x);
int check_box(int x, int y, int value);
void solution(int depth);

int coordinate[81][2];
int num_blank=0;

int main(void){
	int i=0;int j=0;
	int cnt=0;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			scanf("%d", &board[i][j]);
		}
	}
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(board[i][j]==0){
				coordinate[cnt][0]=i;
				coordinate[cnt][1]=j;
				cnt++;
			}
		}
	}
	num_blank=cnt;
	cnt=0;
	//printf("%d\n", num_blank);
	solution(0);
	
	return 0;
}

int check_row(int what_row, int value){
	for(int i=0;i<9;i++){
		if(board[what_row][i]==value){
			return 0;
		}
	}
	return 1;
}

int check_col(int what_col, int value){
	for(int i=0;i<9;i++){
		if(board[i][what_col]==value){
			return 0;
		}
	}
	return 1;
}

int check_box(int x, int y, int value){
	int nx=(x/3)*3;int ny=(y/3)*3;
	for(int i=nx;i<nx+3;i++){
		for(int j=ny;j<ny+3;j++){
			if(board[i][j]==value){
				return 0;
			}
		}
	}
	return 1;
}

void solution(int depth){//depth는 0~num_blank까지. 만약 num_blank에 도달한거면 꽉 채운거니까 return 하자. 
	if(depth==num_blank){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	for(int i=1;i<10;i++){
		if(check_row(coordinate[depth][0], i)&&check_col(coordinate[depth][1],i)&&check_box(coordinate[depth][0],coordinate[depth][1],i)){
			//printf("%d\n", depth);
			board[coordinate[depth][0]][coordinate[depth][1]]=i;
			solution(depth+1);
		}
	}
	board[coordinate[depth][0]][coordinate[depth][1]]=0;
}






