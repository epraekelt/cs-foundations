HDRS=include/utils.h
CPP=src/entry.cpp

all: $(HDRS CPP)
	g++ -I include -o bin/Foundations $(HDRS) $(CPP)

clean:
	rm -f bin/Foundations
