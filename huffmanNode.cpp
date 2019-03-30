#include "huffmanNode.h"

HuffmanNode::HuffmanNode()
{

}
HuffmanNode::HuffmanNode(char l, int f)
{
  letter = l;
  frequency = f;
  leaf = true;
}
HuffmanNode::HuffmanNode(int f, std::shared_ptr<HuffmanNode> l, std::shared_ptr<HuffmanNode> r)
{
  frequency = f;
  left = l;
  right = r;
}
HuffmanNode::HuffmanNode(const HuffmanNode & rhs): letter(rhs.letter), frequency(rhs.frequency),leaf(rhs.leaf)
{
  left = rhs.left;
  right = rhs.right;
}
HuffmanNode::HuffmanNode(HuffmanNode && rhs): letter(rhs.letter), frequency(rhs.frequency),leaf(rhs.leaf)
{
  left = rhs.left;
  right = rhs.right;

  rhs.letter = '\0';
  rhs.frequency = 0;
  rhs.leaf = false;

}
HuffmanNode::~HuffmanNode()
{
}
