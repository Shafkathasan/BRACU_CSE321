#include <stdio.h>
int main()
{
	int radius;
    float area, perimeter;
	
	printf("Input Redis : ");
	scanf("%d", &radius);
	
	perimeter = 2*3.14*radius;
	area = 3.14*radius*radius;
	
	printf("Perimeter of circle : %f \n",perimeter);
	printf("Area of circle : %f \n",area);
	
	return 0;
}
