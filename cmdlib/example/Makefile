all:
	gcc -fPIC -Wall -g -c libexample.c
	gcc -g -shared -Wl,-soname,libexample.so -o ../libexample.so libexample.o
	ar rcs ../libexample.a libexample.o

lib:

clean:
	rm -f *.o ../libexample.so ../libexample.a
