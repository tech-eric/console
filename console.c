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

#include "console.h"
#include "string.h"
#include "stdio.h"

#define SPACE 0x20

/* Make a function pointer typedefine */
typedef int (*FUNC)(int segment_amount, int *offset_array, char *string);

/*
*  A console command
*  @name: the command name
*  @func: the pointer to function that have the same name with command.
*/
struct cmd{
	char *name;
	FUNC func;
};

int test(int  segment_amount, int *offset_array, char *string)
{
    printf("%s, %d, %d\n", __func__, __LINE__, segment_amount);

    return 0;
}

static struct cmd cmd_list[] = {
	{"test", &test},
};

#define cmd_num sizeof(cmd_list)/sizeof(cmd_list[0])

/* Define for used function */
static int string_divide(char *str, int *record);

/*
 * @console_parser: function to paser the input command string,
 *     and call the corresponding function.
 * @string: The input cmd string
 * @return: paser status.
 *   0: success
 *  -1: failed
 */
int console_parser(const char *string)
{
	int i;
    /* The amount that cmd string devided */
    int segment_amount;
    /* Buffer for storing cmd string */
    char cmd_buf[CMD_BUF_SIZE];
    /* Array that store the offset for every segment in cmd string */
    int  offset_array[CMD_SEGMENT_COUNT];

    /* Make sure input string not empty */
    if(string[0] == '\0') {
        printf("Error: Command string is empty\n");
        return -1;
    }

    /* Make sure input string length is not override */
    if(strlen(string) > CMD_BUF_SIZE) {
        printf("Error: Command string is too long\n");
        return -1;
    }

    /* Copy input string to bufer */
    strcpy(cmd_buf, string);

    /* Divid cmd string into several segment, end with '\0' */
    segment_amount = string_divide(cmd_buf, offset_array);

    if(segment_amount < 0) {
        return -1;
    }
	//string_first(string, cmd_name);

	for (i = 0; i < cmd_num; i++) {
		if((strcmp(&cmd_buf[offset_array[0]], cmd_list[i].name)) == 0)
					cmd_list[i].func(segment_amount, offset_array, cmd_buf);
	}

	return 0;
}


/* Find the next space character */
static int next_space(char *str, int i)
{
		if (str[i] == '\0')
			return -1;
		if (str[i] == SPACE)
			return i;
		else
			return next_space(str, ++i);
}

/* Find the next normal character */
static int next_char(char *str, int i)
{
		if (str[i] == '\0')
			return -1;
		else if (str[i] != SPACE )
			return i;
		else
			return next_char(str, ++i);
}

/*
*  string_divide: divide string to several section according space label
*  @str: the input string.
*  @record: a pointer to array that record the string section start address.
*  @return: the section number
*/
static int string_divide(char *str, int *record)
{
		int i = 0;//index for str
		int j = 0;//index for record.
		int ret = 0;
		int cnt = 0;//divide number

		for ( ; ; ) {

				if((ret = next_char(str, i)) >= 0) {
						if(cnt++ > CMD_SEGMENT_COUNT) {
                            printf("ERROR: Command have too many paramer\n");
                            return -1;
                        }
						record[j++] = ret;
						i = ret +1;
				} else
						break;

				if((ret = next_space(str, i)) >= 0) {
						str[ret] = '\0';
						i = ret + 1;
				}else
						break;
		}
		return cnt;
}

