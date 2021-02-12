create-temp-dir:
	- mkdir temp

test-pair: create-temp-dir
	g++ -g -o temp/pair.o pair.cpp
	temp/pair.o
	rm temp/pair.o

test-array: create-temp-dir
	g++ -g -o temp/array.o array.cpp
	temp/array.o
	rm temp/array.o
