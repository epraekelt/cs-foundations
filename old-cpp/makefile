FILES=src/entry.cpp src/Controller.cpp

all: $(FILES)
	g++ -std=c++14 -g -I include -I./term-react/src/preprocessor/include -o bin/Foundations $(FILES)

clean:
	rm -f bin/Foundations

run: all
	@x-terminal-emulator -e bin/Foundations