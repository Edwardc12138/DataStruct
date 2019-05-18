# 搜索当前目录下所有以.c结尾的文件,生成一个以空格间隔的文件名列表并赋值给SRC
#SRC = $(wildcard ./*.c)
# 在SRC中找到所有.c结尾的文件,然后将其全部转换成.o
#OBJ = $(patsubst %.c, %.o, $(src))

#StackTest : $(OBJ)
#	gcc $^ -o $@

#%.o : %.c %.h
#	gcc -c $< -o $@

#.PHONY : clean
#clean:
#	rm *.o StackTest

StackTest : StackTest.o Stack.o
	gcc -g StackTest.o Stack.o -o StackTest
StackTest.o : StackTest.c Stack.h
	gcc -c StackTest.c -o StackTest.o
Stack.o : Stack.c Stack.h
	gcc -c Stack.c -o Stack.o

.PHONY : clean
clean :
	rm -rf Stack.o StackTest.o StackTest
