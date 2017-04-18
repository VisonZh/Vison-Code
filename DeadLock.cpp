#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
#include<errno.h>

using namespace std;

#define NUM 5
//pthread_mutex_t g_lock[NUM] = {PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER};
pthread_mutex_t g_lock[NUM];

void InitLock()
{
	for(int i = 0; i< NUM; i++)
	{
		//g_lock[i] = PTHREAD_MUTEX_INITIALIZER;
		pthread_mutex_init(&g_lock[i],NULL);
	}
}

void DestroyLock()
{
	for(int i = 0; i< NUM;i++)
	{
		pthread_mutex_destroy(&g_lock[i]);
	}
}

void *ThinkEat(void* tag)
{
	char phi = *((char*)tag);
	int left, right;
	switch(phi)
		{
			case 'A':
				left = 4; 
				right = 0;
				break;
			case 'B':
				left = 0; 
				right = 1;
				break;
			case 'C':
				left = 1; 
				right = 2;
				break;
			case 'D':
				left = 2; 
				right = 3;
				break;
			case 'E':
				left = 3; 
				right = 4;
				break;
		}

		for(;;)
		{
			int SleepTime = rand()%10+1;
			sleep(SleepTime);
			//usleep(SleepTime);
			pthread_mutex_lock(&g_lock[left]);
			printf("Philosopher %c fetches chopstick %d\n", phi, left);
			if(EBUSY ==  pthread_mutex_trylock(&g_lock[right]))
			{
				pthread_mutex_unlock(&g_lock[left]);
				continue;
			}
			//pthread_mutex_lock(g_lock[right]);//将上述if语句去掉，则会出现死锁现象
			printf("Philosopher %c fetches chopstick %d\n", phi, right);

			printf("Philosopher %c eating\n", phi);
			sleep(SleepTime);
			//usleep(SleepTime);
			
			pthread_mutex_unlock(&g_lock[right]);
			printf("Philosopher %c releases chopsticks %d\n",phi, right);
			pthread_mutex_unlock(&g_lock[left]);
			printf("Philosopher %c releases chopsticks %d\n",phi, left);
			
			
			
		}
}



int main(void)
{
	srand(time(NULL));
	pthread_t Ptid[NUM];

	InitLock();
	pthread_create(&Ptid[0], NULL, ThinkEat, (void*)"A");
	pthread_create(&Ptid[1], NULL, ThinkEat, (void*)"B");
	pthread_create(&Ptid[2], NULL, ThinkEat, (void*)"C");
	pthread_create(&Ptid[3], NULL, ThinkEat, (void*)"D");
	pthread_create(&Ptid[4], NULL, ThinkEat, (void*)"E");
	
	
	pthread_join(Ptid[0], NULL);
	pthread_join(Ptid[1], NULL);
	pthread_join(Ptid[2], NULL);
	pthread_join(Ptid[3], NULL);
	pthread_join(Ptid[4], NULL);

	DestroyLock();
	
	return 0;
}
