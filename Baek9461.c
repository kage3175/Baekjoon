#include <stdio.h>
#include <stdlib.h>

int n;
long long arr_side[101]={0,1, 1, 1, 2, 2, 3, 4, 5, 7, 9,};

long long length_side(int nth);

int main(void){
	int t=0;
	for(int i=10;i<101;i++) arr_side[i]=0;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%d", &n);
		printf("%lld\n", length_side(n));
	}
	
	return 0;
}

long long length_side(int nth){
	if(arr_side[nth]!=0) return arr_side[nth];
	arr_side[nth]=length_side(nth-1)+length_side(nth-5);
	return arr_side[nth];
}
