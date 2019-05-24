SRC=$(wildcard ./*.c)
#OBJ=$(patsubst %.c, %.o, $(SRC));

HeapTest:$(SRC)
	gcc $^ -o $@

#%.o:%.c %.h
#	gcc $< -o $@

.PHONY:clean
clean:
	rm -rf HeapTest
