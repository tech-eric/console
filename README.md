# console
It's aim to build a common console lib for systemless project
Description:

1. This is a console command parser, you can interaction with the system just using Linux system. It can parser
   your input command  and parameter, then call the corresponding command.

2. Using method.

 Step 1: Download source code. git clone git@github.com:tech-eric/console.git

 Step 2: compile the source code. run "make" in the source code path

 Step 3: copy the generated libconsole.a and console.h to your project path

 Step 4: make sure your callback function have the follow format.
   /*
    *  @function_name: callback function name
    *  @segment_amount: show the command string have how many segment. the string order is like this:
    *   function(seg 0)  parameter1(seg 1) parameter2(seg 2) ....
    *  @offset_array: array store the offset for every segment in command string
    *  @return: status
    */
   example: int function_name(int segment_amount, int *offset_array, char *string)

   so, the function name is: string[offset_array[0]],  the first parameter is string[offset_array[1]], the second parameter is
   string[offset_array[2]]......

 Step 5: add your callback function to the cmd_list array using console_cmd_register function.

 Step6: include console.h in your source file, and then you can use the console_parser function to analysis the input command.

 Step7: build command for project.
       if your project have a main.c file and using the console_parser function. you should specify the library path and
       name in your build command. for example:

       gcc -o main main.c -L PATHTOLIBRARY -lconsole
