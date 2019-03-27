#Makefile
#Pieter Gerhard Serton
#27/03/19

CC=g++

driver: huffmanNode.o huffmanTree.o driver.o
	$(CC) -o compress driver.o huffmanTree.o huffmanNode.o

driver.o: driver.cpp
	$(CC) -c -o driver.o driver.cpp

huffmanTree.o: huffmanTree.cpp
	$(CC) -c -o huffmanTree.o huffmanTree.cpp

huffmanNode.o: huffmanNode.cpp
	$(CC) -c -o huffmanNode.o huffmanNode.cpp

clean:
	@rm -f *.o

debug: huffmanNode.o huffmanTree.o driver.o
	$(CC) -g driver.cpp huffmanTree.cpp huffmanNode.cpp
