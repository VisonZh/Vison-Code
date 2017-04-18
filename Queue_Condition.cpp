#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

using namespace std;

#define NUM  5

int Queue[NUM];


pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_has_product = PTHREAD_COND_INITIALIZER;
//sem_t blank_number, product_number;

void *Product(void *q)
{
	int p = 0;
	for(;;)
	{
		
		pthread_mutex_lock(&g_lock);
		//sem_wait(&blank_number);
		Queue[p] = rand()%1000+1;
		printf("Produce %d\n", Queue[p]);
		p = (p + 1)%NUM;
		pthread_mutex_unlock(&g_lock);
		pthread_cond_signal(&g_has_product);
		//sem_post(&product_number);
		sleep(rand()%5);
		//usleep(rand()%5);
	}		
}


//该函数为新进后出，FILO(frist in last out )
void *Consumer(void *p)
{
	int c = 0;
	for(;;)
	{
		pthread_mutex_lock(&g_lock);
		while(0 == Queue[c])
			pthread_cond_wait(&g_has_product,&g_lock);
		
		//sem_wait(&product_number);
		printf("\t\t\tConsume %d\n", Queue[c]);
		Queue[c] = 0;
		c = (c + 1) % NUM;
		//sem_post(&blank_number);
		pthread_mutex_unlock(&g_lock);
		sleep(rand()%5);
		//usleep(rand()%5);
	}
		
}

int main(void)
{
	pthread_t Ptid, Ctid;

	//sem_init(&blank_number, 0 ,NUM);
	//sem_init(&product_number, 0 ,0);

	
	pthread_create(&Ptid, NULL, Product, NULL);
	pthread_create(&Ctid, NULL, Consumer,  NULL);
	
	pthread_join(Ptid, NULL);
	pthread_join(Ctid, NULL);

	//sem_destroy(&blank_number);
	//sem_destroy(&product_number);

	
	
	return 0;
}
