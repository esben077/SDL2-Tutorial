all:
	g++ -I SDL2/src/include -L SDL2/src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2