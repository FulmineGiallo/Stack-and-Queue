
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
  // lasd::Vector<std::string> v(2);
  // v[0] = "A";
  // v[1] = "B";



  // lasd::StackVec<int> stack;
  // lasd::StackLst<std::string> stack2(v);
  //
  // // lasd::StackLst<int> stack1;
  // // stack.Push(1);
  // // stack.Push(2);
  // // stack.Push(3);
  //
  // // // 3 2 1
  // // int size = stack.Size();
  // // std::cout << "Size" << size << std::endl;
  // //
  // std::cout << "Size STACKLIST" << stack2.Size() << std::endl;
  // std::cout << "Size VEC" << v.Size() << std::endl;
  //
  // for(int i = 0; i < 2; i++)
  // {
  //     std::cout << "Elemento estratto" << stack2.TopNPop() << std::endl;
  // }


  // std::cout << "==" << (stack == stack2)<< std::endl;
  return 0;
}
