ERRFLAGS = -W -Wall -Wextra
OPTFLAGS = -std=c11
GTK = `pkg-config --libs --cflags gtk+-3.0`
CC = gcc $(ERRFLAGS) $(OPTFLAGS)



hello: hello_world.c
	$(CC) -o $@ $< $(GTK)

window: window.o main_window.o
	$(CC) -o $@ $^ $(GTK)

paned: paned.o main_window.o
	$(CC) -o $@ $^ $(GTK)

window.o: window.c
	$(CC) -c $< $(GTK)

paned.o: paned.c
	$(CC) -c $< $(GTK)

main_window.o: main_window.c
	$(CC) -c $< $(GTK)


clean:
	rm -f *.o hello window paned
