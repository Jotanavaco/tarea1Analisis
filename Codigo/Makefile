programa: tarea1.o Ordenador.o
	g++ -o programa tarea1.o Ordenador.o
tarea1.o: tarea1.cc
	g++ -c tarea1.cc
Ordenador.o: Ordenador.h Ordenador.cpp	
	g++ -c Ordenador.h Ordenador.cpp	
clean: 
	rm -f programa *.o *.gch
