#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int t_id[2]={1,2};
void *t_func(int *id);
int main(){
	pthread_t t[2];
	pthread_create(&t[0],NULL,t_func,&t_id[0]);
	pthread_join(t[0],NULL);

	pthread_create(&t[1],NULL,t_func,&t_id[1]);
	
	pthread_join(t[1],NULL);

	
	return 0;
}
void *t_func(int *id){
	printf("Entered in Thread %d...\n",*id);
	for(int i=0;i<5;i++){
		printf("Thread %d Turn %d\n",*id,i);
		sleep(1);
	}
	printf("Ending Thread %d...\n",*id);
}
