all:
	gcc -fPIC -Wall -g -c libstatus.c
	gcc -g -shared -Wl,-soname,libstatus.so -o ../libstatus.so libstatus.o
	ar rcs ../libstatus.a libstatus.o

lib:

clean:
	rm -f *.o ../libstatus.so ../libstatus.a
