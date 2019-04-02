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
  bool leaf = false;

  HuffmanNode();
  HuffmanNode(char l, int f);
  HuffmanNode(int f, std::shared_ptr<HuffmanNode> l, std::shared_ptr<HuffmanNode> r);
  HuffmanNode(const HuffmanNode & rhs);
  HuffmanNode(HuffmanNode && rhs);
  ~HuffmanNode();

  bool operator > (const HuffmanNode & a) const
  {
    return frequency < a.frequency;
  }
  bool operator < (const HuffmanNode & a) const
  {
    return frequency > a.frequency;
  }
  HuffmanNode & operator = (const HuffmanNode & rhs)
  {
    letter = rhs.letter;
    frequency = rhs.frequency;
    leaf = rhs.leaf;
    left = rhs.left;
    right = rhs.right;
    return * this;
  };
  HuffmanNode & operator = (HuffmanNode && rhs)
  {
    letter = rhs.letter;
    frequency = rhs.frequency;
    leaf = rhs.leaf;
    left = rhs.left;
    right = rhs.right;

    rhs.letter = '\0';
    rhs.frequency = 0;
    rhs.leaf = false;
    rhs.left = nullptr;
    rhs.right = nullptr;

    return * this;
  };

};

#endif
