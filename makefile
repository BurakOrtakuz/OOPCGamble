all: main work
main:
	gcc -c -I "./include" ./src/Person.c -o ./lib/Person.o
	gcc -c -I "./include" ./src/GetFile.c -o ./lib/GetFile.o
	gcc -c -I "./include" ./src/Game.c -o ./lib/Game.o
	gcc -c -I "./include" ./src/Main.c -o ./lib/Main.o	
	gcc ./lib/Main.o ./lib/Person.o ./lib/GetFile.o ./lib/Game.o -o ./bin/program.exe
work:	
	.\bin\program.exe