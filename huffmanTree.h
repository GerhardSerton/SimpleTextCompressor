#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
#include "huffmanNode.h"

class Compare
{
public:
    bool operator() (HuffmanNode, HuffmanNode)
    {
        return true;
    }
};

class HuffmanTree
{
private:
  std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> queue;
  std::unordered_map<char, int> charmap;

public:
  HuffmanTree();

  void readFile(std::string fileinname);
  void createTree();
  void writeFile(std::string fileoutname);
  void insertIntoQueue(HuffmanNode h);
  void readIntoMap(char c);

  int mapAt(char c);
  std::shared_ptr<HuffmanNode> createHuffmanNode(char c);
};
#endif
