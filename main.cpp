
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

#include "stack/vec/stackvec.hpp"
#include "stack/lst/stacklst.hpp"
#include "vector/vector.hpp"
/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main()
{
  std::cout << "Lasd Libraries 2020" << std::endl;
  lasdtest();
  lasd::Vector<int> v(3);
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  lasd::StackVec<int> stack(v);


  // lasd::StackLst<int> stack1;
  // stack.Push(1);
  // stack.Push(2);
  // stack.Push(3);
  // stack1.Push(1);
  // stack1.Push(2);
  // stack1.Push(3);
  // // 3 2 1
  int size = stack.Size();
  std::cout << "Size" << size << std::endl;
  std::cout << "Indice" << stack.indice << std::endl;
  for(int i = 0; i < 4; i++)
  {
      std::cout << "Indice" << stack.indice << std::endl;
      std::cout << "Sentinella" << stack.sentinella << std::endl;
      std::cout << stack.TopNPop() << std::endl;

  }


  return 0;
}
