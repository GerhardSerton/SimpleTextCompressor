#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "huffmanTree.h"
#include "huffmanNode.h"
#include "catch.hpp"

TEST_CASE("File Read Tests")
{
  HuffmanTree tree;
  tree.readFile("test.txt");
  REQUIRE(tree.mapAt('a') == 2);
  REQUIRE(tree.mapAt('b') == 1);
  REQUIRE(tree.mapAt('c') == 1);
  REQUIRE(tree.mapAt('\n') == 1);
}
