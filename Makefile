CC := gcc
CFLAGS := -Wall -Wextra -std=c11

calc: main.o	parser.o	operacoes.o
	$(CC) $(CFLAGS) main.o parser.o operacoes.o -o $@
main.o:	main.c	parser.h	operacoes.h
	$(CC) $(CFLAGS) -c main.c 
parser.o:	parser.h	parser.c
	$(CC) $(CFLAGS) -c parser.c
operacoes.o:	operacoes.h	operacoes.c
	$(CC) $(CFLAGS) -c operacoes.c

clean:
	rm -f calc *.o
