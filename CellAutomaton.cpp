#include "Cell.hpp"
#include "Automaton.hpp"
#include <iostream>
#include <time.h>
#include <cstdlib>

int main()
{
  //Automaton maton(time(NULL));
  Automaton maton;

  maton.draw(std::cout);
    
  for(int i=0;i<ADD_MAX;i++){
    maton.foward();
    maton.draw(std::cout);
  }
  
  return 0;
}
