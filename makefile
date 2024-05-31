all:
	g++ chess.cpp chess_functions.cpp -o Chess -I src/include -L src/lib -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -std=c++17