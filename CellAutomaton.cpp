#include "Cell.hpp"
#include "Automaton.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
  Automaton maton(1);


  maton.draw(std::cout);
    
  for(int i=0;i<ADD_MAX;i++){
    maton.foward();
    maton.draw(std::cout);
  }
  
  return 0;
}
