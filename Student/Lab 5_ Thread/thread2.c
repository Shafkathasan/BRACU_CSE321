#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *func_thread(int *n);
void *t_ret;
int num=3;
int main(){
	pthread_t t1;
	pthread_create(&t1,NULL,(void *)func_thread,&num);
	pthread_join(t1,&t_ret);
	printf("Thread returned: %s\n",(char *)t_ret);
	
	return 0;
}

void *func_thread(int *n){
	printf("Entered in Thread:\n");
	if(*n % 2==0){
		pthread_exit("Even");
	}
	else{
		pthread_exit("Odd");
	}
}
