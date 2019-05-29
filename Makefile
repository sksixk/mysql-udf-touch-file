LIBDIR=/usr/local/mysql/lib

install:
	gcc -fPIC -Wall -I/usr/local/mysql/include -I. -shared lib_touch_file.c -o $(LIBDIR)/plugin/lib_touch_file.so
