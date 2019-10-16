all: exe clean

exe: Main.o Plane.o Planes.o CrewMember.o CrewMembers.o Flight.o Flights.o
	g++ -o exe Main.o Plane.o Planes.o CrewMember.o CrewMembers.o Flight.o Flights.o

Main.o: Header.h
	g++ -c Main.cpp

Plane.o: Plane.h
	g++ -c Plane.cpp

Planes.o: Plane.h Planes.h
	g++ -c Planes.cpp

CrewMember.o: CrewMember.h
	g++ -c CrewMember.cpp

CrewMembers.o: CrewMember.h CrewMembers.h
	g++ -c CrewMembers.cpp

Flight.o: Flight.h
	g++ -c Flight.cpp

Flights.o: Flight.h Flights.h
	g++ -c Flights.cpp

clean:
	rm *.o