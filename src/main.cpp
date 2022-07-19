/**
 * @file main.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 19/Jul/2022
 *
 */

#include <iostream>
#include "./classes/include/gene.hpp"

using namespace std;

int main(void)
{
  Gene testGene('A', 'B');
  cout << testGene << endl;
  return 0;
}
