#include <stdio.h>
int main()
{
	int height, width;
	
	printf("Enter Height : ");
	scanf("%d", &height);
	
	printf("Enter Width : ");
	scanf("%d", &width);
	
	int area = height * width;
	
	printf("Area of a rectengula: %d\n",area);
	
	return 0;
	
}
