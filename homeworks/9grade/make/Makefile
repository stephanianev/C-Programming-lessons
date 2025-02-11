all: help.exe strlenght.exe strconcat.exe strcompare.exe

help.exe: help.c
	gcc help.c -o help.exe

mystrings.o: mystrings.h mystrings.c
	gcc -c mystrings.h mystrings.c -o mystrings.o

strlenght.exe: mystrings.h strlenght.c
	gcc strlenght.c -o strlenght.exe

strconcat.exe: mystrings.h strconcat.c
	gcc strconcat.c -o strconcat.exe

strcompare.exe: mystrings.h strcompare.c
	gcc strcompare.c -o strcompare.exe

clean:
	del -f *.exe *.o