#include <iostream>
#include <string>
#include "huffmanTree.h"
#include "huffmanNode.h"

using namespace std;
int main (int argc, char*argv[])
{
  cout << "File accessed: " << argv[1] << " Output file: " << argv[2] << "\n";
  HuffmanTree tree;
  tree.readFile(argv[1]);
  tree.createTree();
  tree.writeFile(argv[2]);

}
