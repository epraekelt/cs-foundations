HDRS=include/utils.h include/Sort.h
CPP=src/entry.cpp src/Sort.cpp

all: $(HDRS CPP)
	g++ -I include -o bin/Foundations $(HDRS) $(CPP)

clean:
	rm -f bin/Foundations
