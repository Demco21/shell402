all: shell402 create list

shell402: shell402.o shellFunctions.o input.o utils.o
	gcc shell402.o shellFunctions.o input.o utils.o -o shell402

list: list.o utils.o listFunctions.o
	gcc list.o utils.o listFunctions.o -o list

create: create.o utils.o
	gcc create.o utils.o -o create

clean:
	rm -f *.o core
