ERRFLAGS = -W -Wall -Wextra
OPTFLAGS = -std=c11
GTK = `pkg-config --libs --cflags gtk+-3.0`
CC = gcc $(ERRFLAGS) $(OPTFLAGS)


clean:
	rm -f *o
