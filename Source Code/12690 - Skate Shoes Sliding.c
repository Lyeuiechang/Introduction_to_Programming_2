#include<stdio.h>

int main(){
	int n = 0;
	char str[10000];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%c", &(str[0]));
	}
	printf("%d\n", n + 1);

	return 0;
}
