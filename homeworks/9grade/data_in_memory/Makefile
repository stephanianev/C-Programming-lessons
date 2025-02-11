all: safeadd.exe safesubtract.exe safemultiply.exe safedivide.exe

safeint.o: safeint.h safeint.c
	gcc safeint.h safeint.c -o -c safeint.o

util.o: util.h util.c
	gcc util.h util.c -o -c util.o

safeadd.exe: safeadd.c safeint.o util.o
	gcc safeadd.c safeint.o util.o -o safeadd.exe

safesubtract.exe: safesubtract.c safeint.o util.o
	gcc safesubtract.c safeint.o util.o -o safesubtract.exe

safemultiply.exe: safemultiply.c safeint.o util.o
	gcc safemultiply.c safeint.o util.o -o safemultiply.exe

safedivide.exe: safedivide.c safeint.o util.o
	gcc safedivide.c safeint.o util.o -o safedivide.exe

clean:
	del -f *.o *.exe