#include <stdio.h>
int main()
{
	int size, i;
	
	printf("Array Size : ");
	scanf("%d", &size);
	
	int arr[size];
	
	printf("\nInput %d elements of array\n",size);
	for(i=0; i<size; i++)
	{
		printf("element - %d : ",i);
		scanf("%d",&arr[i]);
	}
	
	printf("\nElements in array are: ");  
    for(i=0; i<size; i++)  
    {  
        printf("%d  ", arr[i]);  
    } 
    printf("\n");
	
	return 0;
}
