all: create run

create: object_files
	gcc lab2_functions.o lab2.h lab2.c -olab2

object_files:
	gcc lab2_functions.c -c

run: create
	./lab2

clean:
	rm lab2 lab2_functions.o lab2.h.gch 

