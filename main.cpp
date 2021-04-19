
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
  //
  // lasd::QueueVec<int> coda;
  // coda.Enqueue(1);
  // coda.Enqueue(1);
  // coda.Enqueue(1);
  // coda.Enqueue(1);
  // cout << "Testa : " << coda.testa << endl;
  // cout << "Coda  : " << coda.coda << endl;
  // cout << "Size Effettiva : "<< coda.sizeEffettiva << endl;
  // cout << "Size VETTORE : "<< coda.size << endl;
  //
  // coda.Dequeue();
  // coda.Dequeue();
  // coda.Dequeue();
  // coda.Dequeue();
  //
  // // coda.Dequeue();
  // // coda.Dequeue();
  // //
  // cout << "Testa : " << coda.testa << endl;
  // cout << "Coda  : " << coda.coda << endl;
  // cout << "Size Effettiva : "<< coda.sizeEffettiva << endl;
  // cout << "Size VETTORE : "<< coda.size << endl;

  // //Test ==
  // lasd::QueueVec<int> v1;
  // lasd::QueueVec<int> v2;
  // v1.Enqueue(1);
  // v2.Enqueue(1);
  // v1.Enqueue(2);
  // v2.Enqueue(3);
  // cout << (v1 == v2) << endl;

  lasd::Vector<string> v(2);
  v[0] = "A";
  v[1] = "B";

  lasd::QueueVec<string> queue(v);
  cout <<"size effettiva: " << queue.sizeEffettiva << endl;
  cout <<"Coda: " << queue.coda << endl;
  cout << queue.HeadNDequeue() << endl;
  cout << queue.HeadNDequeue() << endl;
  return 0;
}
