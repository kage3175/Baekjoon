#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n; int m;

int arr[100001];
int list[100001];
int static compare(const void*first, const void*second);
int find(int low, int high, int lookfor);

int main(void){
	int high, low, mid;
	int flag=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d", &list[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d", &arr[i]);
	}
	
	low=0;high=n-1;
	qsort(list, n, sizeof(int), compare);
	
	/*for(int i=0;i<n;i++){
		printf("%d ", list[i]);
	}*/
	
	for(int i=0;i<m;i++){
		low=0;high=n-1;flag=0;
		while(high>low){
			if(high-low==1){
				if(list[high]==arr[i]||list[low]==arr[i]){
					flag=1;
					break;
				}
				else{
					break;
				}
			}
			mid=(high+low)/2;
			if(list[mid]==arr[i]){
				flag=1;
				break;
			}
			else if(list[mid]>arr[i]){
				high=mid;
			}
			else{
				low=mid;
			}
		}
		if(flag) printf("1\n");
		else printf("0\n");
	}
	
	
	
	return 0;
}

int static compare(const void*first, const void*second){
	if(*(int*)first>*(int*)second) return 1;
	else if (*(int*)first<*(int*)second) return -1;
	else return 0;
}

int find(int low, int high, int lookfor){
	int mid=(low+high)/2;
	if(list[mid]==lookfor) return 1;
	
}

