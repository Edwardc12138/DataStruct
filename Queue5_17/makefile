QueueTest : QueueTest.o Queue.o
	gcc QueueTest.o Queue.o -o QueueTest
QueueTest.o : QueueTest.c
	gcc -c -g QueueTest.c -o QueueTest.o
Queue.o : Queue.c
	gcc -c -g Queue.c -o Queue.o
.PHONY : clean
clean :
	rm -rf QueueTest.o Queue.o QueueTest
