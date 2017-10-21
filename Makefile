console: console.c
	cc -c console.c
	ar -r libconsole.a console.o
