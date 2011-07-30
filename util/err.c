/*
 * err.c
 *
 *  Created on: Jul 20, 2011
 *      -- Author: makkalot --
 */

#include "err.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

static void output_msg(int num_error, va_list arg_list, const char *format);

void err_num_exit(int num_error, const char *format, ...){

	va_list arg_list;

	va_start(arg_list, format);
	output_msg(num_error, arg_list, format);
	va_end(arg_list);


	exit(EXIT_FAILURE);

}


void err_num_msg(int num_error, const char *format, ...){

	va_list arg_list;

	va_start(arg_list, format);
	output_msg(num_error, arg_list, format);
	va_end(arg_list);

}

void err_sys_exit(const char *format, ...){
	va_list arg_list;

	va_start(arg_list, format);
	output_msg(errno, arg_list, format);
	va_end(arg_list);

	exit(EXIT_FAILURE);
}

void err_sys_msg(const char *format, ...){

	va_list arg_list;

	va_start(arg_list, format);
	output_msg(errno, arg_list, format);
	va_end(arg_list);

}


static void output_msg(int num_error, va_list arg_list, const char *format){
	char buf[BUFSIZ];

	vsnprintf(buf, BUFSIZ, format, arg_list);
	fprintf(stderr, "%s : %s \n", buf, strerror(num_error));

}
