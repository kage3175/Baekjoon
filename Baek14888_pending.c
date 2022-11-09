#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n;int nums[100];int arithmetic[4];
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &nums[i]);
	}
	for(int i=0;i<4;i++) scanf("%d", &arithmetic[i]);
	
	return 0;
}
