#include <stdio.h>
int main()
{
	int var = 20;
	int *ip;
	
	ip = &var;
	
	printf("Address of var variable: %p\n", &var);
	
	printf("Address stored in ip variable: %p\n",ip);
	
	printf("Value of *ip variable: %d\n",*ip);
	
	return 0;
	
}
