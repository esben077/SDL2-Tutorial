all:
	g++ -I SDL2/src/include -L SDL2/src/lib -o main main.cpp item.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image