all: bartoletti_p1.c
	gcc -g -Wall -o bartoletti_p1 bartoletti_p1.c

clean:
	$(RM) bartoletti_p1
