console: console.c
	arm-none-eabi-gcc -c console.c
	arm-none-eabi-ar -r libconsole.a console.o
