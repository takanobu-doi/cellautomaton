#ifndef _AUTOMATON_HPP_
#define _AUTOMATON_HPP_

#include "Cell.hpp"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

class Automaton
{
public:
  Automaton();
  Automaton(int intrand);
  ~Automaton();
  int foward();
  void draw();
  void draw(std::ostream &os);
  void fileout(std::ofstream &fs);
  int s_step();
protected:
  Cell m_cell[ADD_MAX];
  int m_step;
  std::string m_fname;
};

#endif
