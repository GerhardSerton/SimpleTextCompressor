#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>
#include <memory>

class HuffmanNode
{
public:
  char letter = '\0';
  int frequency;
  std::shared_ptr<HuffmanNode> left;
  std::shared_ptr<HuffmanNode> right;
  bool leaf;

  HuffmanNode();
  HuffmanNode(char l, int f);
  HuffmanNode(int f, std::shared_ptr<HuffmanNode> l, std::shared_ptr<HuffmanNode> r);
  HuffmanNode(const HuffmanNode & rhs);
  HuffmanNode(HuffmanNode && rhs);
  ~HuffmanNode();

  HuffmanNode & operator = (const HuffmanNode & rhs)
  {
    HuffmanNode hello;
    HuffmanNode & here = hello;
    return here;
  };

};

#endif
