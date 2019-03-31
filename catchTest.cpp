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
