#include <iostream>
#include <string>
#include "huffmanTree.h"
#include "huffmanNode.h"

using namespace std;
int main (int argc, char*argv[])
{
  cout << "File accessed: " << argv[1] << " Output files: " << argv[2] << " " << argv[2] << ".hdr\n";
  HuffmanTree tree;
  tree.readFile(argv[1]);
  tree.createTree();
  tree.writeFile(argv[2]);
  tree.writeTreeFile(argv[2]);

}
