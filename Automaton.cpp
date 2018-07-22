#include "Automaton.hpp"
#include "Cell.hpp"
#include <iostream>

Automaton::Automaton(int intrand)
{
  std::srand(intrand);
  for(int i=0;i<ADD_MAX;i++){
    m_cell[i].s_life((std::rand())%2);
    m_cell[i].s_address(i);
  }
  m_step = 0;
}

Automaton::~Automaton()
{
}

int Automaton::foward()
{
  Cell temp_cell[ADD_MAX];
  
  temp_cell[0].s_life(m_cell[0].on_off(m_cell[ADD_MAX-1],m_cell[0],m_cell[1]));
  temp_cell[0].s_address(0);
  for(int i=1;i<ADD_MAX-1;i++){
    temp_cell[i].s_life(m_cell[i].on_off(m_cell[i-1],m_cell[i],m_cell[i+1]));
    temp_cell[i].s_address(i);
  }
  temp_cell[ADD_MAX-1].s_life(m_cell[ADD_MAX-1].on_off(m_cell[ADD_MAX-2],m_cell[ADD_MAX-1],m_cell[0]));
  temp_cell[ADD_MAX-1].s_address(ADD_MAX-1);
  
  m_step++;

  for(int i=0;i<ADD_MAX;i++){
    m_cell[i] = temp_cell[i];
  }
  
  return m_step;
}

void Automaton::draw()
{
  for(int i=0;i<ADD_MAX;i++){
     if(m_cell[i].g_life()==on){
       std::cout << on;
    }else if(m_cell[i].g_life()==off){
       std::cout << off;
    }else{
      exit(EXIT_FAILURE);
    }
  }
  
  return;
}

void Automaton::draw(std::ostream &os)
{
  for(int i=0;i<ADD_MAX;i++){
     if(m_cell[i].g_life()==on){
       os << "■";
    }else if(m_cell[i].g_life()==off){
       os << "□";
    }else{
       exit(EXIT_FAILURE);
    }
  }
  os << std::endl;

  return;
}

void Automaton::fileout(std::ofstream &fs)
{
}

int Automaton::s_step()
{
  return m_step;
}
