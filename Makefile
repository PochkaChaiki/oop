all: Kostenko.exe

Kostenko.exe: main.o Character.o Composition.o
	g++ main.o Character.o Composition.o -o Kostenko.exe

main.o: Kostenko_main.cpp utils.h Kostenko_Composition_class.h Kostenko_Character_class.h
	g++ -c Kostenko_main.cpp -o main.o

Character.o: Kostenko_Character_class.cpp Kostenko_Character_class.h utils.h
	g++ -c Kostenko_Character_class.cpp -o Character.o

Composition.o: Kostenko_Composition_class.cpp Kostenko_Composition_class.h Kostenko_Character_class.h utils.h
	g++ -c Kostenko_Composition_class.cpp -o Composition.o