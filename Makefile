all: main.c
	gcc main.c -o csend

run: csend
	./csend

clean:
	rm csend
