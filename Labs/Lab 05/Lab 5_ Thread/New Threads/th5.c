#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *func1(void *arg);
void *func2(void *arg);
int x=10;
int main(){
	int pid;
	pid=fork();
	if(pid == 0)
	{ /* Child */
	printf("Child here!\n");
	pthread_t t1,t2;
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("-------------------\n");
	}
	else
	{ /* Parent */
	wait();
	printf("Parent here!\n");
	printf("In Parent, x=%d\n",x);
	printf("In Parent, pid=%d\n",getpid());
	}
	
	return 0;
}
void *func1(void *arg){
	x+=5;
	printf("In thread1, x=%d\n",x);
	printf("In thread1, pid=%d\n",getpid());


}

void *func2(void *arg){
	sleep(1);
	printf("In thread2, x=%d\n",x);
	printf("In thread2, pid=%d\n",getpid());
}

