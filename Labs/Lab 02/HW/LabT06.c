#include <stdio.h>
int main()
{
	int sec, h, m, s;
	
	printf("Input Seconds : ");
	scanf("%d", &sec);
	
	h = (sec/3600);
	
	m = (sec - (3600*h))/60;
	
	s = (sec -(3600*h)-(m*60));
	
    printf("Hour:Minute:Second - %d:%d:%d\n",h,m,s);
	
	return 0;
}
