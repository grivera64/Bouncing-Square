default: clean build run
build:
	g++ -std=c++17 ../src/*.cpp -o main.exe -Ofast -Wall -Wno-missing-braces -I ../include/ -L ../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
run:
	./main.exe
clean:
	del main.exe
