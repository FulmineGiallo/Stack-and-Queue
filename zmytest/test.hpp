
#ifndef ZMYTEST_HPP
#define ZMYTEST_HPP

#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"
/* ************************************************************************** */
namespace lasd
{
  template <typename Data>
  void riempi(lasd::StackVec<Data>& v, int n);
  template <typename Data>
  void riempi(lasd::StackLst<Data>& v, int n);
  void MenuUtente();
  void MenuQueue(int tipo, int sceltaVettList, int n);
  void MenuStack(int tipo, int sceltaVettList, int n);
}



/* ************************************************************************** */

#endif
