test:test.c libadd.a libadd.so
	gcc $^ -o $@

libadd.a:add.c
	gcc -c add.c -o add.o
	ar -rc libadd.a add.o

libadd.so:add.c
	gcc add.c -shared -fPIC -o libadd.so
