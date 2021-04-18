
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

#include "stack/vec/stackvec.hpp"
#include "stack/lst/stacklst.hpp"
#include "vector/vector.hpp"
#include "queue/vec/queuevec.hpp"
/* ************************************************************************** */

#include <iostream>
using namespace std;
/* ************************************************************************** */

int main()
{
  std::cout << "Lasd Libraries 2020" << std::endl;
  lasdtest();

  // lasd::QueueVec<int> coda;
  // coda.Enqueue(1);
  // coda.Enqueue(2);
  // coda.Enqueue(2);
  // coda.Enqueue(2);
  //
  // cout << "Testa : " << coda.testa << endl;
  // cout << "Coda  : " << coda.coda << endl;
  // cout << "Size Effettiva : "<< coda.sizeEffettiva << endl;
  // cout << "Size VETTORE : "<< coda.size << endl;
  //
  // coda.Dequeue();
  // coda.Dequeue();
  // coda.Dequeue();
  // coda.Enqueue(2);
  // cout << "Testa : " << coda.testa << endl;
  // cout << "Coda  : " << coda.coda << endl;
  // cout << "Size Effettiva : "<< coda.sizeEffettiva << endl;
  // cout << "Size VETTORE : "<< coda.size << endl;
  return 0;
}
