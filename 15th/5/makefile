gcc:
	gcc -Wall -std=c99 -O2 5.c

debug:
	gcc -Wall -std=c99 -O2 -DDEBUG 5.c

d1:
	make debug
	./a.out < ./counterexamples/1.in

1:
	make gcc
	./a.out < ./counterexamples/1.in > out.txt
	diff out.txt ./counterexamples/1.out	

d2:
	make debug
	./a.out < ./counterexamples/2.in

2:
	make gcc
	./a.out < ./counterexamples/2.in > out.txt
	diff out.txt ./counterexamples/2.out

d3:
	make debug
	./a.out < ./counterexamples/3.in

3:
	make gcc
	./a.out < ./counterexamples/3.in > out.txt
	diff -u out.txt ./counterexamples/3.out	

s-alld:
	make debug
	echo "========== 3.in =========="
	./a.out < ./counterexamples/3.in
	echo "answer = 1 <- 0 <- 4"
	echo "========== 4.in =========="
	./a.out < ./counterexamples/4.in
	echo "answer = 3 <- 1 <- 0"
	echo "========== 2.in =========="
	./a.out < ./counterexamples/2.in
	echo "answer = 4 <- 0 <- 1 <- 5"

s-all:
	make gcc
	@echo "========== 3.in =========="
	./a.out < ./counterexamples/3.in
	@echo "answer = 1 <- 0 <- 4"
	@echo "========== 4.in =========="
	./a.out < ./counterexamples/4.in
	@echo "answer = 3 <- 1 <- 0"
	@echo "========== 2.in =========="
	./a.out < ./counterexamples/2.in
	@echo "answer = 4 <- 0 <- 1 <- 5"