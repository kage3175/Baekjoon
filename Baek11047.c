#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n, k;
	int coin[11]={0};
	int ans=0;
	scanf("%d %d", &n, &k);
	for(int i=1;i<n+1;i++) scanf("%d", &coin[i]);
	
	for(int i=n;i>=1;i--){
		ans+=k/coin[i];
		k=k%coin[i];
	}
	printf("%d", ans);
	return 0;
}
