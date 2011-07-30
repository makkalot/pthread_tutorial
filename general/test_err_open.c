/*
 * test.c
 *
 *  Created on: Jul 23, 2011
 *      Author: makkalot
 */

#include "../util/err.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char *argv[]){

	int fd;

	if((fd = open("nonexisting_file.txtx", O_RDONLY)) < 0)
		err_sys_exit("open");

	return 0;
}
