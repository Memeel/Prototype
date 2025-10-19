main: main.o carproto.o busproto.o vanproto.o
	g++ -o main main.o carproto.o busproto.o vanproto.o
main.o: main.cpp vehicle.h carproto.h busproto.h vanproto.h
	g++ -c main.cpp
carproto.o: carproto.cpp carproto.h vehicle.h
	g++ -c carproto.cpp
busproto.o: busproto.cpp busproto.h vehicle.h
	g++ -c busproto.cpp
vanproto.o: vanproto.cpp vanproto.h vehicle.h
	g++ -c vanproto.cpp
clean:
	rm -f main *.o
