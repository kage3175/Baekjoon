#include <stdio.h>

int main(void){
	char buf[8];
	double* pd;
	int* pi;
	
	pd=(double*)buf;
	*pd=1.1;
	printf("%p %f\n", pd, *pd);
	buf[0]=1.1;
	printf("%p %f %f", buf, buf[0], *pd);

	
	return 0;
}
