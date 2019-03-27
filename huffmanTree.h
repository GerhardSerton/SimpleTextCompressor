#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <string>
#include <queue>
#include "huffmanNode.h"

class HuffmanTree
{
private:
public:
  HuffmanTree();
  HuffmanTree(const HuffmanTree & rhs);
  HuffmanTree(HuffmanTree && rhs);
  ~HuffmanTree();
  HuffmanTree & operator = (const HuffmanTree & rhs);


}
