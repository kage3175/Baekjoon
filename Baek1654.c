#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int n;int k;
long long line[10001];
long long low=1;long long high=0;long long mid;
long long length=0;

int main(void){
	scanf("%d %d",&k, &n);
	for(int i=0;i<k;i++){
		scanf("%lld", &line[i]);
		if(line[i]>high) high=line[i];
	}
	
	while(1){
		int cnt=0;

		mid=(high+low)/2;
		if(high==low){
			for(int i=0;i<k;i++){
				cnt+=line[i]/mid;
			}
			if(cnt>=n){
				low=mid+1;
				if(length<mid) length=mid;
			}
			else{
				high=mid-1;
			}
		}
		else if(high<low) break;
		//printf("%d %d %d\n", high, low, mid);		
		for(int i=0;i<k;i++){
			cnt+=line[i]/mid;
		}
		if(cnt>=n){
			low=mid+1;
			if(length<mid) length=mid;
		}
		else{
			high=mid-1;
		}
	}
	
	printf("%lld", length);
	
	return 0;
}
