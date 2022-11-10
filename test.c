#include <stdio.h>
#include <stdlib.h>

int p[3]={0,1,2};


int main(void){
	int v=0;
	printf("%d %d\n", *p, ++(*p));
	printf("%d\n", *(p+1));	
}
