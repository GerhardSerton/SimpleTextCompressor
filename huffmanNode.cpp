#include "huffmanNode.h"

HuffmanNode::HuffmanNode()
{}
HuffmanNode::HuffmanNode(char l, int f)
{
  letter = l;
  frequency = f;
}
HuffmanNode::HuffmanNode(int f, std::shared_ptr<HuffmanNode> l, std::shared_ptr<HuffmanNode> r)
{
  frequency = f;
  left = l;
  right = r;
}
HuffmanNode::HuffmanNode(const HuffmanNode & rhs)
{}
HuffmanNode::HuffmanNode(HuffmanNode && rhs)
{}
HuffmanNode::~HuffmanNode()
{}
//HuffmanNode & operator = (const HuffmanNode & rhs)
