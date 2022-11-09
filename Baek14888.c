#include <stdio.h>
#include <stdlib.h>

int n;
int* arr_num;
int arr_arith[4]={0};
int* order;
int max=-1000000001;
int min=1000000001;

int calculate(void);
void solution(int depth);

int main(void){
	int i=0;
	scanf("%d", &n);
	arr_num=(int*)malloc(sizeof(int)*n);
	order=(int*)malloc(sizeof(int)*(n-1));
	for(i=0;i<n-1;i++) order[i]=-1;
	for(i=0;i<n;i++){
		scanf("%d", &arr_num[i]);
	}
	for(i=0;i<4;i++){
		scanf("%d", &arr_arith[i]);
	}
	
	solution(0);
	
	printf("%d\n%d\n", max, min);
	
	free(order);
	free(arr_num);
	return 0;
}

int calculate(void){
	int result=arr_num[0];
	for(int i=0;i<n-1;i++){
		switch(order[i]){
			case 0:
				result+=arr_num[i+1];
				break;
			case 1:
				result-=arr_num[i+1];
				break;
			case 2:
				result*=arr_num[i+1];
				break;
			case 3:
				result/=arr_num[i+1];
				break;
			default:
				printf("something wrong!\n");
				break;
		}
	}
	return result;
}

void solution(int depth){
	int result;
	if(depth==n-1){
		result=calculate();
		if(result>max){
			max=result;
		}
		if(result<min){
			min=result;
		}
		
	}
	for(int i=0;i<4;i++){
		if(arr_arith[i]>=1){
			arr_arith[i]-=1;
			order[depth]=i;
			solution(depth+1);
			arr_arith[i]+=1;
			order[depth]=-1;
		}
	}
	
	
}



