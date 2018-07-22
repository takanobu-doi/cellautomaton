#include "Cell.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

Cell::Cell()
{
  m_life = off;
}

Cell::Cell(int plife)
{
  if(plife == 0){
    m_life = off;
  }else if(plife == 1){
    m_life = on;
  }else{
    exit(EXIT_FAILURE);
  }
}

Cell::~Cell()
{
}

LIFE Cell::g_life()
{
  return m_life;
}

int Cell::g_address()
{
  return m_address;
}

void Cell::s_life(int plife)
{
  if(plife == 0){
    m_life = off;
  }else if(plife == 1){
    m_life = on;
  }else{
    exit(EXIT_FAILURE);
  }
  return;
}

void Cell::s_life(LIFE plife)
{
  m_life = plife;
  return;
}

void Cell::s_address(int paddress)
{
  m_address = paddress;
  return;
}

LIFE Cell::on_off()//2-dem ver.
{
  Cell *pthis = this;
  int pattern=0;
  
  if(m_address>0&&m_address<ADD_MAX-1){
    for(int i=0;i<3;i++){
      pattern += (int)pthis[i-1].g_life()*pow(2,i);
    }
  }else if(m_address==0){
    pattern += (int)pthis[0].g_life()*2;
    pattern += (int)pthis[1].g_life()*4;
    pattern += (int)pthis[ADD_MAX-1].g_life();
  }else if(m_address==ADD_MAX-1){
    pattern += (int)pthis[0].g_life()*2;
    pattern += (int)pthis[-1].g_life();
    pattern += (int)pthis[-ADD_MAX+1].g_life()*4;
  }

  return rule(pattern);
}
LIFE Cell::on_off(Cell c1,Cell c2,Cell c3)//2-dem ver.
{
  int pattern=0;
  pattern += (int)c1.g_life();
  pattern += (int)c2.g_life()*2;
  pattern += (int)c3.g_life()*4;

  return rule(pattern);
}

LIFE Cell::rule(int pattern)
{
  switch(pattern){
  case 0:
    return off;
  case 1:
    return on;
  case 2:
    return on;
  case 3:
    return off;
  case 4:
    return on;
  case 5:
    return on;
  case 6:
    return off;
  case 7:
    return off;
  default:
    std::cerr << "rule failure" << std::endl;
    exit(EXIT_FAILURE);
  }
}

Cell & Cell::operator = (Cell &his)
{
  m_life = his.g_life();
  m_address = his.g_address();

  return *this;
}
