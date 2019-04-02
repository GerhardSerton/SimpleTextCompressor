#include "huffmanTree.h"

HuffmanTree::HuffmanTree()
{}
HuffmanTree::HuffmanTree(const HuffmanTree & rhs)
{
  queue = rhs.queue;
  charmap = rhs.charmap;
  quickmap = rhs.quickmap;
  inputname = rhs.inputname;
  root = rhs.root;
}
HuffmanTree::HuffmanTree(HuffmanTree && rhs)
{
  queue = rhs.queue;
  charmap = rhs.charmap;
  quickmap = rhs.quickmap;
  inputname = rhs.inputname;
  root = rhs.root;

  rhs.root = nullptr;
  rhs.inputname = "";
  rhs.charmap.clear();
  rhs.quickmap.clear();
}
HuffmanTree::~HuffmanTree()
{
  root = nullptr;
}
void HuffmanTree::readFile(std::string fileinname)
{
  inputname = fileinname;
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
      //auto x = std::make_shared<HuffmanNode>(n.first, n.second);
      HuffmanNode x (n.first, n.second);
      queue.push(x);
    }
    //std::cout << queue.top().letter << " " << queue.top().frequency << "queue\n";
  }

  else
  {
    std::cout << "File not found";
  }
  inputFile.close();

}
void HuffmanTree::createTree()
{
  while (queue.size() > 1)
  {
    auto leftPtr = std::make_shared<HuffmanNode>(queue.top());
    queue.pop();
    auto rightPtr = std::make_shared<HuffmanNode>(queue.top());
    queue.pop();
    int f = HuffmanNode(*leftPtr).frequency + HuffmanNode(*rightPtr).frequency;
    HuffmanNode z (f, leftPtr, rightPtr);
    queue.push(z);
    //std::cout << queue.top().frequency << "queue\n";
  }
  root = std::make_shared<HuffmanNode>(queue.top());
  queue.pop();
}
void HuffmanTree::writeFile(std::string fileoutname)
{
  //traverseTree("", queue.top());
  traverseTree("", *root);
  std::ifstream inputFile (inputname);
  std::ofstream outputFile (fileoutname);
  if (inputFile.is_open())
  {
    char currentChar;
    while ((inputFile.get(currentChar), inputFile.eof()) == false)
    {
      outputFile << quickmap[currentChar];

    }

  }
  else
  {
    std::cout << "File not found";
  }
  inputFile.close();
  outputFile.close();

}
void HuffmanTree::writeTreeFile(std::string fileoutname)
{
  std::ofstream treeFile (fileoutname + ".hdr");
  treeFile << quickmap.size() << "\n";
  for (auto & it: quickmap)
  {
    treeFile << it.first << " " << it.second << "\n";
  }
  treeFile.close();

}
void HuffmanTree::insertIntoQueue(HuffmanNode h)
{}
void HuffmanTree::readIntoMap(char c)
{
  charmap[c] = charmap[c] + 1;

}
void HuffmanTree::traverseTree(std::string code, HuffmanNode h)
{
  //std::cout << "Frequency: " << h.frequency << " Leaf: " << h.leaf << "\n";
  if (h.leaf)
  {
    quickmap[h.letter] = code;

    //std::cout << "Character: " << h.letter << " Code: " << quickmap[h.letter] << "\n";
  }
  else
  {
    traverseTree(code + "0", HuffmanNode(*h.left));
    traverseTree(code + "1", HuffmanNode(*h.right));
  }
}
int HuffmanTree::mapAt(char c)
{
  return charmap[c];
}

std::string HuffmanTree::codeAt(char c)
{
  return quickmap[c];
}

HuffmanNode HuffmanTree::getTree()
{
  return queue.top();
}
std::shared_ptr<HuffmanNode> HuffmanTree::createHuffmanNode(char c)
{
  std::shared_ptr<HuffmanNode> newNode = std::make_shared<HuffmanNode>(c, charmap[c]);
  return newNode;
}
