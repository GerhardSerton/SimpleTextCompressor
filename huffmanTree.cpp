#include "huffmanTree.h"

HuffmanTree::HuffmanTree()
{}
void HuffmanTree::readFile(std::string fileinname)
{
  std::ifstream inputFile (fileinname);
  if (inputFile.is_open())
  {
    char currentChar;
    while ((inputFile.get(currentChar), inputFile.eof()) == false)
    {
      readIntoMap(currentChar);
      //std::cout << currentChar <<": " << charmap[currentChar] << "\n";
    }

    for (const auto  & n: charmap)
    {
      //std::cout << n.first << " " << n.second << "\n";
      HuffmanNode x (n.first, n.second);
      queue.push(x);
    }
  }
  else
  {
    std::cout << "File not found";
  }

}
void HuffmanTree::createTree()
{}
void HuffmanTree::writeFile(std::string fileoutname)
{}
void HuffmanTree::writeTreeFile(std::string fileoutname)
{}
void HuffmanTree::insertIntoQueue(HuffmanNode h)
{}
void HuffmanTree::readIntoMap(char c)
{
  charmap[c] = charmap[c] + 1;
}

int HuffmanTree::mapAt(char c)
{
  return charmap[c];
}

std::shared_ptr<HuffmanNode> HuffmanTree::createHuffmanNode(char c)
{
  std::shared_ptr<HuffmanNode> newNode = std::make_shared<HuffmanNode>(c, charmap[c]);
  return newNode;
}
