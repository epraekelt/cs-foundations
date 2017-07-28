HDRS=include/utils.h include/sort/insertion.h
CPP=src/entry.cpp src/sort/insertion.cpp

all: $(HDRS CPP)
	g++ -I include -o bin/Foundations $(HDRS) $(CPP)

clean:
	rm -f bin/Foundations
