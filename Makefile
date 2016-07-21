CFLAGS=-Wall -Werror -g -ggdb

all:
	cc sortingAlgos.c 	-o sortIt

clean:
	rm -f sortIt


