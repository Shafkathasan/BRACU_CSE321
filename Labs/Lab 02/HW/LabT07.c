#include <stdio.h>
int main()
{
	int x, y;
	
	printf("Enter the value of x and y\n");
    scanf("%d%d",&x,&y);
	
	printf("Before Swapping\nx = %d\ny = %d\n", x, y);
	
	x = x+y;
	y = x-y;
	x = x-y;
	
    printf("After Swapping\nx = %d\ny = %d\n", x, y);
	
	return 0;
}
