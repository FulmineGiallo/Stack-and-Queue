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
  int scelta = -1;
  std::cout << "Lasd Libraries 2020" << std::endl;
  std::cout << "Benvenuto nell'esercizio 2 - Guarracino Carmine Matricola: " << std::endl;
  while(scelta != 0)
  {
    std::cout << "1: Per scegliere il MENU LASDTEST del Prof Mogavero" << std::endl;
    std::cout << "2: Per scegliere il MENU Dei Test personali" << std::endl;
    std::cout << "0: Per uscire dal programma" << std::endl;
    cin >> scelta;
    if(scelta == 1)
      lasdtest();
    if(scelta == 2)
      lasd::MenuUtente();
  }

  return 0;
}
