main: main.o studentRecord.o studentLL.o
	gcc -o main main.o studentRecord.o studentLL.o

main.o : main.c studentRecord.h studentLL.h
	gcc -Wall -Werror -c main.c

studentRecord.o : studentRecord.c studentRecord.h
	gcc -Wall -Werror -c studentRecord.c

studentLL.o : studentLL.c studentLL.h studentRecord.h
	gcc -Wall -Werror -c studentLL.c

clean:
	rm -f main main.o studentRecord.o studentLL.o core

