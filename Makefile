
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c11 -g $(WARNING) $(ERROR)


main: 
	$(GCC) main.c A01.c -o A01 
.c.o: 
	$(GCC) -c $*.c

test1: A01
	./A01 inputs/input1.txt >> output1
	diff output1 expected/expected1	
