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

/* Max size for cmd buffer */
#define CMD_BUF_SIZE  32
/* Max amount the cmd string can be divided */
#define CMD_SEGMENT_COUNT 5 

/*
 * @console_parser: console command parser function
 * @string: pointer to command string's start address
 * @retun: parser status.
 *   0: success
 *  -1: failed
 */
extern int console_parser(const char *string);

#endif

