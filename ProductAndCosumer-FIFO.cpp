#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>

using namespace std;

typedef struct msg COMMDODITY;  
struct msg
{
	unsigned int num;
	COMMDODITY * next;
};

pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_has_product = PTHREAD_COND_INITIALIZER;
COMMDODITY * g_head;



void *Product(void *p)
{
	COMMDODITY *mp;
	for(;;)
	{
		mp = (COMMDODITY*)new COMMDODITY[sizeof(COMMDODITY)];
		mp->num = rand()%1000+1;
		printf("Produce %d\n", mp->num);
		//mp->next = NULL;
		pthread_mutex_lock(&g_lock);
		mp->next = g_head;
		g_head = mp;
		pthread_mutex_unlock(&g_lock);
		pthread_cond_signal(&g_has_product);
		sleep(rand()%5);
	}		
}

//该函数为新进后出，FILO(frist in last out )
void *Consumer(void *p)
{
	COMMDODITY *mp, *Del_PreNode,*Del_Node;
	for(;;)
	{
		pthread_mutex_lock(&g_lock);
		while(NULL == g_head)
			pthread_cond_wait(&g_has_product,&g_lock);
		
		mp = g_head ;
		if(NULL == mp->next)
		{
			printf("\t\t\tConsume %d\n", mp->num);
			delete mp;
			g_head = NULL;
			pthread_mutex_unlock(&g_lock);
			sleep(rand()%5);
		}
		else
		{
			while(mp->next)
			{
				Del_PreNode = mp;
				Del_Node = mp->next;
				mp = mp->next;
			}
			printf("\t\t\tConsume %d\n", Del_Node->num);
			delete Del_Node;
			Del_PreNode->next = Del_Node = NULL;
			pthread_mutex_unlock(&g_lock);
			sleep(rand()%5);
			
		}

	}
		
}

int main(void)
{
	pthread_t Ptid, Ctid;

	pthread_create(&Ptid, NULL, Product, NULL);
	
	pthread_create(&Ctid, NULL, Consumer,  NULL);
	pthread_join(Ptid, NULL);
	pthread_join(Ctid, NULL);
	
	return 0;
}
