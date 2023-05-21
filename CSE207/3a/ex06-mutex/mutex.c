/*
 * mutex.c
 *
 *  Created on: Mar 19, 2016
 *      Author: jiaziyi
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 50
void *increase_counter(void *);
pthread_mutex_t lock;

int  counter = 0;

int main()
{

	//create 50 threads of increase_counter, each thread adding 1 to the counter
	pthread_t threads[NTHREADS];
	int rc;
	long t;
	for(t=0; t<NTHREADS; t++){
		rc = pthread_create(&threads[t], NULL, increase_counter, NULL);
		if (rc){
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			return -1;
		}
	}

	//wait for all threads to finish
	for(t=0; t<NTHREADS; t++){
		pthread_join(threads[t], NULL);
	}


	printf("\nFinal counter value: %d\n", counter);
}

void *increase_counter(void *arg)
{


    pthread_mutex_lock(&lock);            // START critical region
	printf("Thread number %ld, working on counter. The current value is %d\n", (long)pthread_self(), counter);
	int i = counter;
	usleep (10000); //simulate the data processing
	counter = i+1;
	pthread_mutex_unlock(&lock);          // END critical region

	return NULL;

}
