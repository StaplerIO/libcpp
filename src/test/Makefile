create-temp-dir:
	@- mkdir temp

test-pair: create-temp-dir
	gcc -o temp/pair.o pair.cpp
	temp/pair.o
	rm temp/pair.o