main: main.o carproto.o busproto.o vanproto.o
	gcc -o main main.o carproto.o busproto.o vanproto.o
main.o: main.cpp vehicle.h carproto.h busproto.h vanproto.h
	gcc -c main.cpp
carproto.o: carproto.cpp carproto.h vehicle.h
	gcc -c carproto.cpp
busproto.o: busproto.cpp busproto.h vehicle.h
	gcc -c busproto.cpp
vanproto.o: vanproto.cpp vanproto.h vehicle.h
	gcc -c vanproto.cpp
clean:
	rm -f main *.o