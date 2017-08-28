FILES=src/entry.cpp src/Controller.cpp

all: $(FILES)
	g++ -std=c++11 -I include -o bin/Foundations $(FILES)

clean:
	rm -f bin/Foundations
