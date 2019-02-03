gcc:
	@gcc -Wall -std=c99 -O2 7.c

d:
	@gcc -Wall -std=c99 -O2 -DDEBUG 7.c

d1:
	@make debug
	@./a.out < ./counterexamples/1.in

1:
	@make gcc
	@./a.out < ./counterexamples/1.in > out.txt
	@diff out.txt ./counterexamples/1.out	

d2:
	@make debug
	@./a.out < ./counterexamples/2.in

2:
	@make gcc
	@./a.out < ./counterexamples/2.in > out.txt
	@diff out.txt ./counterexamples/2.out

d3:
	@make debug
	@./a.out < ./counterexamples/3.in

3:
	@make gcc
	@./a.out < ./counterexamples/3.in > out.txt
	@diff -u out.txt ./counterexamples/3.out	

exe:
	@make gcc
	@./a.out