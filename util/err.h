/*
 * err.h
 *
 *  Created on: Jul 20, 2011
 *      Author: makkalot
 */

#ifndef ERR_H_
#define ERR_H_

extern void err_num_exit(int errnum, const char *format, ...);
extern void err_num_msg(int errnum, const char *format, ...);

extern void err_sys_exit(const char *format, ...);
extern void err_sys_msg(const char *format, ...);

#endif /* ERR_H_ */
