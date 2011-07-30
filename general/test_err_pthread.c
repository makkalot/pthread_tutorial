/*
 * test.c
 *
 *  Created on: Jul 23, 2011
 *      Author: work
 */

#include "../util/err.h"

#include <pthread.h>
#include <signal.h>

int main(int argc, char *argv[]){

	int result;

	if((result = pthread_kill(pthread_self(), 222)) != 0)
		err_num_exit(result, "pthread_kill");

	return 0;
}
