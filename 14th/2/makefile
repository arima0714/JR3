gcc:
	gcc -Wall -std=c99 -O2 2.c

debug:
	gcc -Wall -std=c99 -O2 -DDEBUG 2.c

d1:
	make debug
	./a.out < ./counterexamples/1.in

1:
	make gcc
	./a.out < ./counterexamples/1.in > out.txt
	diff out.txt ./counterexamples/1.out	