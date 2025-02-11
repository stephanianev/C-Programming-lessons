taskmanager.exe: processes.o taskmanager.c
	gcc taskmanager.c processes.o -o taskmanager.exe

processes.o: processes.c
	gcc -c processes.c -o processes.o

clean:
	del -f *.o *.exe