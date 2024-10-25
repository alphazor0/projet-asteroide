main :  main.o mobile.o asteroide.o
		g++ main.o mobile.o asteroide.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
		./sfml-app
		
main.o : main.cpp
	g++ -c main.cpp


mobile.o : mobile.cpp mobile.h
	g++ mobile.cpp -c -Wfatal-errors

asteroide.o : asteroide.cpp asteroide.h
	g++ asteroide.cpp -c -Wfatal-errors
