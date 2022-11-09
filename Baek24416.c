#include <stdio.h>
#include <stdlib.h>

int f[50]={0};
int count_fib=0;
int count_fibbonacci=0;

int fib(int n){
	if(n==1||n==2){
		count_fib++;
		return 1;
	}
	else return (fib(n-1)+fib(n-2));
}

int fibbonacci(int n){
	f[1]=1;
	f[2]=1;
	for(int i=3;i<=n;i++){
		count_fibbonacci++;
		f[i]=f[i-1]+f[i-2];
	}
	return f[n];
}

int main(void){
	int n=0;
	scanf("%d", &n);
	fib(n);
	fibbonacci(n);
	printf("%d %d\n", count_fib, count_fibbonacci);
	
	return 0;
}
