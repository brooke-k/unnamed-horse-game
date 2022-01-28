/**
 * File: Main.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com)
 * Date: 27/Jan/2022
 *
 */

#include <iostream>
#include "./headers/TeraHorse.hpp"

using namespace std;

int main(void)
{
  Horse beefHorse("Peanuts", (int)sizeof("Peanuts") / sizeof(char), 'M', 8);
  TeraHorse beep("Beepers", strlen("Beepers"), 'F', true, 10);
  cout << beefHorse;
  cout << beep;

  return 0;
}