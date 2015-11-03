all:
	gcc -fPIC -Wall -g -c libghn.c
	gcc -g -shared -Wl,-soname,libghn.so -o ../libghn.so libghn.o
	ar rcs ../libghn.a libghn.o
lib:

clean:
	rm -f *.o ../libghn.so ../libghn.a
