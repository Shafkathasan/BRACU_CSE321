#include <stdio.h>

int main()
{
	int n, i, sum=0;
	printf("Input number : ");
	scanf("%d",&n);
	
	for(i=1; i<=n; i++) {
		if (i%2==0) sum = sum + i;
		//printf("%d\n",sum);
	}
	
	printf("Sum of all even number between 1 to %d = %d \n", n, sum);
}
