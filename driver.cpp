#include <iostream>
#include <string>
#include "huffmanTree.h"
#include "huffmanNode.h"

using namespace std;
int main (int argc, char*argv[])
{
  string inputfile = argv[1];
  string outputfile = argv[2];
  HuffmanTree tree;
  tree.readFile(argv[1]);

}
