
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c11 -g $(WARNING) $(ERROR)


main: 
	$(GCC) main.c A01.c -o  a1 
.c.o: 
	$(GCC) -c $*.c

test1: a1
	/a1 testcase_0.txt > my_output.txt
	diff my_output.txt output_0.txt
