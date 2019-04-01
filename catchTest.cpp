#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include <string>
#include "huffmanTree.h"
#include "huffmanNode.h"
#include "catch.hpp"

TEST_CASE("File Read Tests")
{
  HuffmanTree tree;
  tree.readFile("test.txt");
  REQUIRE(tree.mapAt('a') == 3);
  REQUIRE(tree.mapAt('b') == 2);
  REQUIRE(tree.mapAt('c') == 2);
  REQUIRE(tree.mapAt('d') == 2);
  REQUIRE(tree.mapAt('e') == 2);
  REQUIRE(tree.mapAt('f') == 1);
  REQUIRE(tree.mapAt('\n') == 1);
}

TEST_CASE("Tree Navigation Tests")
{
  HuffmanTree tree;
  tree.readFile("test.txt");
  tree.createTree();
  tree.writeFile("unitTestResults.txt");
  REQUIRE(tree.codeAt('a') == "01");
  REQUIRE(tree.codeAt('b') == "110");
  REQUIRE(tree.codeAt('c') == "111");
  REQUIRE(tree.codeAt('d') == "00");
  REQUIRE(tree.codeAt('e') == "100");
  REQUIRE(tree.codeAt('f') == "1011");
  REQUIRE(tree.codeAt('\n') == "1010");

}

TEST_CASE("File Output Check")
{
  HuffmanTree tree;
  tree.readFile("test.txt");
  tree.createTree();
  tree.writeFile("unitTestResults.txt");
  std::ifstream fileIn("unitTestResults.txt");
  std::string line;
  std::getline(fileIn, line);
  REQUIRE(line == "011101110010010110111011100100011010");
}

TEST_CASE("Header File Output Check")
{
  HuffmanTree tree;
  tree.readFile("test.txt");
  tree.createTree();
  tree.writeFile("unitTestResults.txt");
  tree.writeTreeFile("unitTestResults.txt");
  std::ifstream fileIn("unitTestResults.txt.hdr");
  std::string line;
  std::getline(fileIn, line);
  REQUIRE(line == "7");
  std::string s;
  bool pass = true;
  while ((std::getline(fileIn, s), fileIn.eof()) == false)
  {
    if (s == "c 111")
    {}
    else if (s == "a 01")
    {}
    else if (s == "d 00")
    {}
    else if (s == "e 100")
    {}
    else if (s == "")
    {}
    else if (s == " 1010")
    {}
    else if (s == "f 1011")
    {}
    else if (s == "b 110")
    {}
    else
    {pass = false;}
  }
  REQUIRE(pass);
}
