#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>

class HuffmanNode
{
public:
  char letter;
  int frequency;

  HuffmanNode();
  HuffmanNode(char letter, int frequency);
  ~HuffmanNode();
  bool compare(const HuffmanNode & a, const HuffmanNode & b);
}
