AXL_test: main.o AXL.o AX3L.o matrix.o
	gcc -o run main.o AXL.o matrix.o AX3L.o -L/usr/X11/lib -lX11 -lm
	make rm

main.o : main.c AXL.h AX3L.h
	gcc -c -Wall main.c

AXL.o : AXL.c AXL.h
	gcc -c -Wall AXL.c

AX3L.o : AX3L.c AX3L.h AXL.h matrix.h
	gcc -c -Wall AX3L.c
	
matrix.o : matrix.c matrix.h
	gcc -c -Wall matrix.c
	
rm :
	rm *.o
