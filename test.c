#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *a;
char *b;

int main(void){
	int n=6;
	a=(char*)malloc(sizeof(char)*n);
	b=(char*)malloc(sizeof(char)*n);
	
	scanf("%s", a);
	b[0]=a[0];
	printf("%c", b[0]);
	
	free(a);
	free(b);	
	return 0;
}
