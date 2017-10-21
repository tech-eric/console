/*
 *  Description: This is a integrated libary file, used to give a
 *  console interaction function for systemless project. You can
 *  get, modify and share this file, but make sure not to delete
 *  this description please.
 *  Author: Eric Gao "eric.gao@foxmail.com"
 *  Date: 2017.10.21
 *  License: GPL2.0
 *
 */

#ifndef __CONSOLE_H
#define __CONSOLE_H

/* Max size for cmd buffer in byte */
#define CMD_BUF_SIZE  32
/* Max amount the cmd string can be divided */
#define CMD_SEGMENT_COUNT 5
/* Max console command amount */
#define CMD_LIST_MAX 10

/* Callback function model */
typedef int (*FUNC)(int segment_amount,int *offset_array,char *string);

/*
 * @console_cmd_register: register callback function into console.
 * @name: callback function alias in console.
 * @func: callback function name(also pointer)
 * @return: status
 *  0: success
 * -1: failed
 */
extern int console_cmd_register(char *name, const FUNC func);

/*
 * @console_parser: console command parser function
 * @string: pointer to command string's start address
 * @retun: parser status.
 *   0: success
 *  -1: failed
 */
extern int console_parser(const char *string);

#endif

