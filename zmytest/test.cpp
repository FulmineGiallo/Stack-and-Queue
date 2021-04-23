
#include <string.h>
#include <string>
#include <typeinfo>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>    // std::shuffle
#include <iostream>
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../vector/vector.hpp"
#include "../queue/vec/queuevec.hpp"
#include "test.hpp"
using namespace std;

namespace lasd
{

  std::string chars {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
  std::random_device rd;
  std::mt19937 generator(rd());
  std::string rand_str (int length)
  {
      std::string output (chars);
      std::shuffle(output.begin(), output.end(), generator);
      return output.substr(0, length);
    }
  template<typename Data>
  void riempi(StackVec<Data>& v, int dim)
  {
        Data dataRandom;
        srand ((unsigned int)time(NULL));
        std::string type_name();

        for(unsigned int i = 0; i < dim; i++)
        {
           dataRandom = (Data)rand() / 100 + 1;
           v.Push(dataRandom);
        }
}
  void riempiString(StackVec<string>& v, int dim)
  {
    for(unsigned int i=0; i < dim; i++)
    {
       v.Push(rand_str(5));
    }
}
  template<typename Data>
  void riempi(StackLst<Data>& v, int dim)
  {
        Data dataRandom;
        srand ((unsigned int)time(NULL));
        std::string type_name();
        for(unsigned int i = 0; i < dim; i++)
        {
           dataRandom = (Data)rand() / 100 + 1;
           v.Push(dataRandom);
        }
  }
  void riempiString(StackLst<string>& v, int dim)
  {
    for(unsigned int i=0; i < dim; i++)
    {
       v.Push(rand_str(5));
    }
  }
  template<typename Data>
  void riempi(QueueVec<Data>& v, int dim)
  {
        Data dataRandom;
        srand ((unsigned int)time(NULL));
        std::string type_name();

        for(unsigned int i = 0; i < dim; i++)
        {
           dataRandom = (Data)rand() / 100 + 1;
           v.Enqueue(dataRandom);
        }
}
  void riempiString(QueueVec<string>& v, int dim)
  {
    for(unsigned int i=0; i < dim; i++)
    {
       v.Enqueue(rand_str(5));
    }
  }
  template<typename Data>
  void riempi(QueueLst<Data>& v, int dim)
  {
        Data dataRandom;
        srand ((unsigned int)time(NULL));
        std::string type_name();
        for(unsigned int i = 0; i < dim; i++)
        {
           dataRandom = (Data)rand() / 100 + 1;
           v.Enqueue(dataRandom);
        }
  }
  void riempiString(QueueLst<string>& v, int dim)
  {
    for(unsigned int i=0; i < dim; i++)
    {
       v.Enqueue(rand_str(5));
    }
  }

  void MenuQueue(int dato, int sceltaVettList, int n)
  {
    lasd::QueueVec<int>    queuevec_int;
    lasd::QueueVec<double> queuevec_double;
    lasd::QueueVec<float>  queuevec_float;
    lasd::QueueVec<string> queuevec_string;

    lasd::QueueLst<int>    queuelst_int;
    lasd::QueueLst<double> queuelst_double;
    lasd::QueueLst<float>  queuelst_float;
    lasd::QueueLst<string> queuelst_string;
    if(sceltaVettList == 1) //Caso Vettore
    {
        if(dato == 1)
        {
          riempi(queuevec_int, n);
        }
        if(dato == 2)
        {
          riempi(queuevec_double, n);
        }
        if(dato == 3)
        {
          riempi(queuevec_float, n);
        }
        if(dato == 4)
        {
          riempiString(queuevec_string, n);
        }
      }
    if(sceltaVettList == 2) //Caso Lista
    {
      if(dato == 1)
      {
        riempi(queuelst_int, n);
      }
      if(dato == 2)
      {
        riempi(queuelst_double, n);
      }
      if(dato == 3)
      {
        riempi(queuelst_float, n);
      }
      if(dato == 4)
      {
        riempiString(queuelst_string, n);
      }
  }
    int scelta = -1;
    while( scelta != 0)
    {
      if(sceltaVettList == 1)
        cout << "Benvenuto nello QueueVec - Menu" << endl;
      if(sceltaVettList == 2)
        cout << "Benvenuto nello QueueLst - Menu" << endl;

      cout << "1) Push " << endl;
      cout << "2) Pop " << endl;
      cout << "3) TopNPop" << endl;
      cout << "4) Top" << endl;
      cout << "5) Test Vuotezza" << endl;
      cout << "6) Dimensione Stack" << endl;
      cout << "7) Svuota Stack" << endl;
      cout << "0) Per uscire dal programma" << endl;
      cin  >> scelta;

      if(sceltaVettList == 1)
      {
        if(scelta == 1 && dato == 1)
        {
          int num = 0;
          cout << "Che elemento vuoi inserire nella Queue?" << endl;
          cin  >> num;
          queuevec_int.Enqueue(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 2)
        {
          double num = 0;
          cout << "Che elemento vuoi inserire nello Queue?" << endl;
          cin  >> num;
          queuevec_double.Enqueue(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 3)
        {
          float num = 0;
          cout << "Che elemento vuoi inserire nello Queue?" << endl;
          cin  >> num;
          queuevec_float.Enqueue(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 4)
        {
          std::string num;
          cout << "Che elemento vuoi inserire nello Stack?" << endl;
          cin  >> num;
          queuevec_string.Enqueue(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 2 && dato == 1)
        {
          cout << "Pop eseguito con successo" << endl;
          queuevec_int.Dequeue();
        }
        if(scelta == 2 && dato == 2)
        {
          cout << "Pop eseguito con successo" << endl;
          queuevec_double.Dequeue();
        }
        if(scelta == 2 && dato == 3)
        {
          cout << "Pop eseguito con successo" << endl;
          queuevec_float.Dequeue();
        }
        if(scelta == 2 && dato == 4)
        {
          cout << "Pop eseguito con successo" << endl;
          queuevec_string.Dequeue();
        }
        if(scelta == 3 && dato == 1)
        {
          cout << "Elemento Rimosso: " << queuevec_int.HeadNDequeue() << endl;
        }
        if(scelta == 3 && dato == 2)
        {
          cout << "Elemento Rimosso: " << queuevec_double.HeadNDequeue() << endl;
        }
        if(scelta == 3 && dato == 3)
        {
          cout << "Elemento Rimosso: " << queuevec_float.HeadNDequeue() << endl;
        }
        if(scelta == 3 && dato == 4)
        {
          cout << "Elemento Rimosso: " << queuevec_string.HeadNDequeue() << endl;
        }
        if(scelta == 4 && dato == 1)
        {
          cout << "Elemento : " << queuevec_int.Head() << endl;
        }
        if(scelta == 4 && dato == 2)
        {
          cout << "Elemento : " << queuevec_double.Head() << endl;
        }
        if(scelta == 4 && dato == 3)
        {
          cout << "Elemento : " << queuevec_float.Head() << endl;
        }
        if(scelta == 4 && dato == 4)
        {
          cout << "Elemento : " << queuevec_string.Head() << endl;
        }
        bool vuoto;
        if(scelta == 5 && dato == 1)
        {
          vuoto = queuevec_int.Empty();
        }
        if(scelta == 5 && dato == 2)
        {
          vuoto = queuevec_double.Empty();
        }
        if(scelta == 5 && dato == 3)
        {
          vuoto = queuevec_float.Empty();
        }
        if(scelta == 5 && dato == 4)
        {
          vuoto = queuevec_string.Empty();
        }
        if(scelta == 5)
        {
          if( vuoto == 1)
            cout << "StackVec vuoto" << endl;
          if( vuoto == 0)
            cout << "StackVec non vuoto" << endl;
        }
        unsigned long dimensione = 0;
        if(scelta ==6 && dato == 1)
        {
          dimensione = queuevec_int.Size();
        }
        if(scelta ==6 && dato == 2)
        {
          dimensione = queuevec_double.Size();
        }
        if(scelta ==6 && dato == 3)
        {
          dimensione = queuevec_float.Size();
        }
        if(scelta ==6 && dato == 4)
        {
          dimensione = queuevec_string.Size();
        }
        if(scelta == 6)
          cout << "Dimensione QueueVec: " << dimensione << endl;
        if(scelta == 7 && dato == 1)
          queuevec_int.Clear();
        if(scelta == 7 && dato == 2)
          queuevec_double.Clear();
        if(scelta == 7 && dato == 3)
          queuevec_float.Clear();
        if(scelta == 7 && dato == 4)
          queuevec_string.Clear();
        if(scelta == 7)
          cout << "QueueVec svuotato" << endl;
      }
      if(sceltaVettList == 2)
      {
        if(scelta == 1 && dato == 1)
        {
          int num = 0;
          cout << "Che elemento vuoi inserire nella Queue?" << endl;
          cin  >> num;
          queuelst_int.Enqueue(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 2)
        {
          double num = 0;
          cout << "Che elemento vuoi inserire nello Queue?" << endl;
          cin  >> num;
          queuelst_double.Enqueue(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 3)
        {
          float num = 0;
          cout << "Che elemento vuoi inserire nello Queue?" << endl;
          cin  >> num;
          queuelst_float.Enqueue(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 4)
        {
          std::string num;
          cout << "Che elemento vuoi inserire nello Stack?" << endl;
          cin  >> num;
          queuelst_string.Enqueue(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 2 && dato == 1)
        {
          cout << "Pop eseguito con successo" << endl;
          queuelst_int.Dequeue();
        }
        if(scelta == 2 && dato == 2)
        {
          cout << "Pop eseguito con successo" << endl;
          queuelst_double.Dequeue();
        }
        if(scelta == 2 && dato == 3)
        {
          cout << "Pop eseguito con successo" << endl;
          queuelst_float.Dequeue();
        }
        if(scelta == 2 && dato == 4)
        {
          cout << "Pop eseguito con successo" << endl;
          queuelst_string.Dequeue();
        }
        if(scelta == 3 && dato == 1)
        {
          cout << "Elemento Rimosso: " << queuelst_int.HeadNDequeue() << endl;
        }
        if(scelta == 3 && dato == 2)
        {
          cout << "Elemento Rimosso: " << queuelst_double.HeadNDequeue() << endl;
        }
        if(scelta == 3 && dato == 3)
        {
          cout << "Elemento Rimosso: " << queuelst_float.HeadNDequeue() << endl;
        }
        if(scelta == 3 && dato == 4)
        {
          cout << "Elemento Rimosso: " << queuelst_string.HeadNDequeue() << endl;
        }
        if(scelta == 4 && dato == 1)
        {
          cout << "Elemento : " << queuelst_int.Head() << endl;
        }
        if(scelta == 4 && dato == 2)
        {
          cout << "Elemento : " << queuelst_double.Head() << endl;
        }
        if(scelta == 4 && dato == 3)
        {
          cout << "Elemento : " << queuelst_float.Head() << endl;
        }
        if(scelta == 4 && dato == 4)
        {
          cout << "Elemento : " << queuelst_string.Head() << endl;
        }
        bool vuoto;
        if(scelta == 5 && dato == 1)
        {
          vuoto = queuelst_int.Empty();
        }
        if(scelta == 5 && dato == 2)
        {
          vuoto = queuelst_double.Empty();
        }
        if(scelta == 5 && dato == 3)
        {
          vuoto = queuelst_float.Empty();
        }
        if(scelta == 5 && dato == 4)
        {
          vuoto = queuelst_string.Empty();
        }
        if(scelta == 5)
        {
          if( vuoto == 1)
            cout << "StackVec vuoto" << endl;
          if( vuoto == 0)
            cout << "StackVec non vuoto" << endl;
        }
        unsigned long dimensione = 0;
        if(scelta ==6 && dato == 1)
        {
          dimensione = queuelst_int.Size();
        }
        if(scelta ==6 && dato == 2)
        {
          dimensione = queuelst_double.Size();
        }
        if(scelta ==6 && dato == 3)
        {
          dimensione = queuelst_float.Size();
        }
        if(scelta ==6 && dato == 4)
        {
          dimensione = queuelst_string.Size();
        }
        if(scelta == 6)
          cout << "Dimensione QueueVec: " << dimensione << endl;
        if(scelta == 7 && dato == 1)
          queuelst_int.Clear();
        if(scelta == 7 && dato == 2)
          queuelst_double.Clear();
        if(scelta == 7 && dato == 3)
          queuelst_float.Clear();
        if(scelta == 7 && dato == 4)
          queuelst_string.Clear();
        if(scelta == 7)
          cout << "QueueVec svuotato" << endl;
      }
    }

  }
  void MenuStack(int dato, int sceltaVettList, int n)
  {
    lasd::StackVec<int>    stackvec_int;
    lasd::StackVec<double> stackvec_double;
    lasd::StackVec<float>  stackvec_float;
    lasd::StackVec<string> stackvec_string;

    lasd::StackLst<int>    stacklst_int;
    lasd::StackLst<double> stacklst_double;
    lasd::StackLst<float>  stacklst_float;
    lasd::StackLst<string> stacklst_string;

    if(sceltaVettList == 1) //Caso Vettor    if(dato == 1)
    {
      {
        riempi(stackvec_int, n);
      }
      if(dato == 2)
      {
        riempi(stackvec_double, n);
      }
      if(dato == 3)
      {
        riempi(stackvec_float, n);
      }
      if(dato == 4)
      {
        riempiString(stackvec_string, n);
      }
    }
    if(sceltaVettList == 2) //Caso Lista
    {
      if(dato == 1)
      {
        riempi(stacklst_int, n);
      }
      if(dato == 2)
      {
        riempi(stacklst_double, n);
      }
      if(dato == 3)
      {
        riempi(stacklst_float, n);
      }
      if(dato == 4)
      {
        riempiString(stacklst_string, n);
      }
    }

    //Inizia il Menu di Stack
    int scelta = -1;
    while( scelta != 0)
    {
      if(sceltaVettList == 1)
        cout << "Benvenuto nello StackVec - Menu" << endl;
      if(sceltaVettList == 2)
        cout << "Benvenuto nello StackLst - Menu" << endl;

      cout << "1) Push " << endl;
      cout << "2) Pop " << endl;
      cout << "3) TopNPop" << endl;
      cout << "4) Top" << endl;
      cout << "5) Test Vuotezza" << endl;
      cout << "6) Dimensione Stack" << endl;
      cout << "7) Svuota Stack" << endl;
      cout << "0) Per uscire dal programma" << endl;
      cin  >> scelta;

      if(sceltaVettList == 1)
      {
        if(scelta == 1 && dato == 1)
        {
          int num = 0;
          cout << "Che elemento vuoi inserire nello Stack?" << endl;
          cin  >> num;
          stackvec_int.Push(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 2)
        {
          double num = 0;
          cout << "Che elemento vuoi inserire nello Stack?" << endl;
          cin  >> num;
          stackvec_double.Push(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 3)
        {
          float num = 0;
          cout << "Che elemento vuoi inserire nello Stack?" << endl;
          cin  >> num;
          stackvec_float.Push(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 4)
        {
          std::string num;
          cout << "Che elemento vuoi inserire nello Stack?" << endl;
          cin  >> num;
          stackvec_string.Push(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 2 && dato == 1)
        {
          cout << "Pop eseguito con successo" << endl;
          stackvec_int.Pop();
        }
        if(scelta == 2 && dato == 2)
        {
          cout << "Pop eseguito con successo" << endl;
          stackvec_double.Pop();
        }
        if(scelta == 2 && dato == 3)
        {
          cout << "Pop eseguito con successo" << endl;
          stackvec_float.Pop();
        }
        if(scelta == 2 && dato == 4)
        {
          cout << "Pop eseguito con successo" << endl;
          stackvec_string.Pop();
        }
        if(scelta == 3 && dato == 1)
        {
          cout << "Elemento Rimosso: " << stackvec_int.TopNPop() << endl;
        }
        if(scelta == 3 && dato == 2)
        {
          cout << "Elemento Rimosso: " << stackvec_double.TopNPop() << endl;
        }
        if(scelta == 3 && dato == 3)
        {
          cout << "Elemento Rimosso: " << stackvec_float.TopNPop() << endl;
        }
        if(scelta == 3 && dato == 4)
        {
          cout << "Elemento Rimosso: " << stackvec_string.TopNPop() << endl;
        }
        if(scelta == 4 && dato == 1)
        {
          cout << "Elemento : " << stackvec_int.Top() << endl;
        }
        if(scelta == 4 && dato == 2)
        {
          cout << "Elemento : " << stackvec_double.Top() << endl;
        }
        if(scelta == 4 && dato == 3)
        {
          cout << "Elemento : " << stackvec_float.Top() << endl;
        }
        if(scelta == 4 && dato == 4)
        {
          cout << "Elemento : " << stackvec_string.Top() << endl;
        }
        bool vuoto;
        if(scelta == 5 && dato == 1)
        {
          vuoto = stackvec_int.Empty();
        }
        if(scelta == 5 && dato == 2)
        {
          vuoto = stackvec_double.Empty();
        }
        if(scelta == 5 && dato == 3)
        {
          vuoto = stackvec_float.Empty();
        }
        if(scelta == 5 && dato == 4)
        {
          vuoto = stackvec_string.Empty();
        }
        if(scelta == 5)
        {
          if( vuoto == 1)
            cout << "StackVec vuoto" << endl;
          if( vuoto == 0)
            cout << "StackVec non vuoto" << endl;
        }
        unsigned long dimensione = 0;
        if(scelta ==6 && dato == 1)
        {
          dimensione = stackvec_int.Size();
        }
        if(scelta ==6 && dato == 2)
        {
          dimensione = stackvec_double.Size();
        }
        if(scelta ==6 && dato == 3)
        {
          dimensione = stackvec_float.Size();
        }
        if(scelta ==6 && dato == 4)
        {
          dimensione = stackvec_string.Size();
        }
        if(scelta == 6)
          cout << "Dimensione StackVec: " << dimensione << endl;
        if(scelta == 7 && dato == 1)
          stackvec_int.Clear();
        if(scelta == 7 && dato == 2)
          stackvec_double.Clear();
        if(scelta == 7 && dato == 3)
          stackvec_float.Clear();
        if(scelta == 7 && dato == 4)
          stackvec_string.Clear();
        if(scelta == 7)
          cout << "StackVec svuotato" << endl;
      }
      if(sceltaVettList == 2)
      {
        if(scelta == 1 && dato == 1)
        {
          int num = 0;
          cout << "Che elemento vuoi inserire nello Stack?" << endl;
          cin  >> num;
          stacklst_int.Push(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 2)
        {
          double num = 0;
          cout << "Che elemento vuoi inserire nello Stack?" << endl;
          cin  >> num;
          stacklst_double.Push(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 3)
        {
          float num = 0;
          cout << "Che elemento vuoi inserire nello Stack?" << endl;
          cin  >> num;
          stacklst_float.Push(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 1 && dato == 4)
        {
          std::string num;
          cout << "Che elemento vuoi inserire nello Stack?" << endl;
          cin  >> num;
          stacklst_string.Push(num);
          cout << "Push effettuato" << endl;
        }
        if(scelta == 2 && dato == 1)
        {
          cout << "Pop eseguito con successo" << endl;
          stacklst_int.Pop();
        }
        if(scelta == 2 && dato == 2)
        {
          cout << "Pop eseguito con successo" << endl;
          stacklst_double.Pop();
        }
        if(scelta == 2 && dato == 3)
        {
          cout << "Pop eseguito con successo" << endl;
          stacklst_float.Pop();
        }
        if(scelta == 2 && dato == 4)
        {
          cout << "Pop eseguito con successo" << endl;
          stacklst_string.Pop();
        }
        if(scelta == 3 && dato == 1)
        {
          cout << "Elemento Rimosso: " << stacklst_int.TopNPop() << endl;
        }
        if(scelta == 3 && dato == 2)
        {
          cout << "Elemento Rimosso: " << stacklst_double.TopNPop() << endl;
        }
        if(scelta == 3 && dato == 3)
        {
          cout << "Elemento Rimosso: " << stacklst_float.TopNPop()<< endl;
        }
        if(scelta == 3 && dato == 4)
        {
          cout << "Elemento Rimosso: " << stacklst_string.TopNPop() << endl;
        }
        if(scelta == 4 && dato == 1)
        {
          cout << "Elemento : " << stacklst_int.Top() << endl;
        }
        if(scelta == 4 && dato == 2)
        {
          cout << "Elemento : " << stacklst_double.Top() << endl;
        }
        if(scelta == 4 && dato == 3)
        {
          cout << "Elemento : " << stacklst_float.Top()<< endl;
        }
        if(scelta == 4 && dato == 4)
        {
          cout << "Elemento : " << stacklst_string.Top()<< endl;
        }
        bool vuoto;
        if(scelta == 5 && dato == 1)
        {
          vuoto = stacklst_int.Empty();
        }
        if(scelta == 5 && dato == 2)
        {
          vuoto = stacklst_double.Empty();
        }
        if(scelta == 5 && dato == 3)
        {
          vuoto = stacklst_float.Empty();
        }
        if(scelta == 5 && dato == 4)
        {
          vuoto = stacklst_string.Empty();
        }
        if(scelta == 5)
        {
          if( vuoto == 1)
            cout << "StackVec vuoto" << endl;
          if( vuoto == 0)
            cout << "StackVec non vuoto" << endl;
        }
        unsigned long dimensione = 0;
        if(scelta ==6 && dato == 1)
        {
          dimensione = stacklst_int.Size();
        }
        if(scelta ==6 && dato == 2)
        {
          dimensione = stacklst_double.Size();
        }
        if(scelta ==6 && dato == 3)
        {
          dimensione = stackvec_float.Size();
        }
        if(scelta ==6 && dato == 4)
        {
          dimensione = stacklst_string.Size();
        }
        if(scelta == 6)
          cout << "Dimensione StackVec: " << dimensione << endl;
        if(scelta == 7 && dato == 1)
          stacklst_int.Clear();
        if(scelta == 7 && dato == 2)
          stacklst_double.Clear();
        if(scelta == 7 && dato == 3)
          stacklst_float.Clear();
        if(scelta == 7 && dato == 4)
          stacklst_string.Clear();
        if(scelta == 7)
          cout << "StackVec svuotato";
      }
    }
}
  void MenuUtente()
  {
    int sceltaStruttura = 0;
    int sceltaVettList  = 0;
    int tipo = 0;
    int n = 0;
    cout << "Benvenuto nel MENU" << endl;
    cout << "Scegli cosa utilizzare: " << endl;
    cout << "1) Stack" << endl;
    cout << "2) Queue" << endl;
    cin  >> sceltaStruttura;
    cout << endl;
    cout << "Scegli tra Vettori o Liste" << endl;
    cout << "1) Vettore" << endl;
    cout << "2) Liste" << endl;
    cin  >> sceltaVettList;
    cout << endl;
    cout << "Che tipo di dato vuoi utilizzare?" << endl;
    cout << "1) Int" << endl;
    cout << "2) Double" << endl;
    cout << "3) Float" << endl;
    cout << "4) String" << endl;
    cin  >> tipo;
    cout << "Quanti elementi vuoi inserire nella struttura?" << endl;
    cin  >> n;

    if(sceltaStruttura == 1)
      MenuStack(tipo, sceltaVettList, n);
    if(sceltaStruttura == 2)
      MenuQueue(tipo, sceltaVettList, n);
    }
}
