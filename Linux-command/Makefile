objects = command.o pwd.o uname.o hostname.o mkdir.o

command : $(objects)
	gcc -o command $(objects)

$(objects) : command.h

.PHONY : clean

clean :
	rm command $(objects)
