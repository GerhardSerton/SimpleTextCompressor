#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
#include "huffmanNode.h"

class HuffmanTree
{
private:
  std::priority_queue<HuffmanNode, std::vector<HuffmanNode>> queue;
  std::unordered_map<char, int> charmap;
  std::unordered_map<char, std::string> quickmap;
  std::string inputname;
  std::shared_ptr<HuffmanNode> root;

public:

  HuffmanTree();
  HuffmanTree(const HuffmanTree & rhs);
  HuffmanTree(HuffmanTree && rhs);
  ~HuffmanTree();

  HuffmanTree & operator = (const HuffmanTree & rhs)
  {
    queue = rhs.queue;
    charmap = rhs.charmap;
    quickmap = rhs.quickmap;
    inputname = rhs.inputname;
    root = rhs.root;

    return * this;
  };
  HuffmanTree & operator = (HuffmanTree && rhs)
  {
    queue = rhs.queue;
    charmap = rhs.charmap;
    quickmap = rhs.quickmap;
    inputname = rhs.inputname;
    root = rhs.root;

    rhs.root = nullptr;
    rhs.inputname = "";

    return * this;
  };

  void readFile(std::string fileinname);
  void createTree();
  void writeFile(std::string fileoutname);
  void writeTreeFile(std::string fileoutname);
  void insertIntoQueue(HuffmanNode h);
  void readIntoMap(char c);
  void traverseTree(std::string code, HuffmanNode h);

  int mapAt(char c);
  std::string codeAt(char c);
  HuffmanNode getTree();
  std::shared_ptr<HuffmanNode> createHuffmanNode(char c);

};
#endif
