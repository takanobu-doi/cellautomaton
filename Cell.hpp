#ifndef _CELL_HPP_
#define _CELL_HPP_

const int ADD_MAX = 30;
enum LIFE{off,on};

class Cell
{
public:
  Cell();
  Cell(int plife);
  ~Cell();
  LIFE g_life();
  int g_address();
  void s_life(int plife);
  void s_life(LIFE plife);
  void s_address(int paddress);
  LIFE on_off();
  LIFE on_off(Cell c1,Cell c2,Cell c3);
  LIFE rule(int pattern);
  Cell & operator = (Cell &his);
protected:
  LIFE m_life;
  int m_address;
};
#endif
