FILES=src/entry.cpp src/Controller.cpp src/Sort.cpp

all: $(FILES)
	g++ -I include -o bin/Foundations $(FILES)

clean:
	rm -f bin/Foundations
