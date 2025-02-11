all: main.exe 

main.exe: main.c quadraticroots.o
	gcc main.c quadraticroots.o -libm -o main.exe

quadraticroots.o: quadraticroots.h quadraticroots.c
	gcc -c quadraticroots.h quadraticroots.c -o quadraticroots.o

clean:
	del -f *.o *.exe