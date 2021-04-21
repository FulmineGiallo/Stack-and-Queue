// 
// // ...
// #include <iostream>
// #include "../stack/vec/stackvec.hpp"
// #include "../stack/lst/stacklst.hpp"
// #include "../vector/vector.hpp"
// #include "../queue/vec/queuevec.hpp"
// using namespace std;
//
// template<typename Data>
// void riempi(StackVec<Data>& v, int n)
// {
//     Data dataRandom;
//     srand ((unsigned int)time(NULL));
//     std::string type_name();
//     for(unsigned int i = 0; i < v.Size(); i++)
//     {
//        dataRandom = (Data)rand() / 100 + 1;
//        v.Push(dataRandom);
//
//        if(typeid(v[0]).name() == "d")
//        {
//           v.Push(trunc(dataRandom));;
//        }
//     }
// }
// // template<typename Data>
// // void riempi(StackLst<Data>& v, int n)
// // {
// //     Data dataRandom;
// //     srand ((unsigned int)time(NULL));
// //     std::string type_name();
// //     for(unsigned int i = 0; i < v.Size(); i++)
// //     {
// //        dataRandom = (Data)rand() / 100 + 1;
// //        v.Push(dataRandom);
// //
// //        if(typeid(v[0]).name() == "d")
// //        {
// //           v.Push(trunc(dataRandom));;
// //        }
// //     }
// // }
//
// void MenuStack(int dato, int sceltaVettList, int n)
// {
//   lasd::StackVec<int>    stackvec_int;
//   lasd::StackVec<double> stackvec_double;
//   lasd::StackVec<float>  stackvec_float;
//   lasd::StackVec<string> stackvec_string;
//
//   lasd::StackLst<int>    stacklst_int;
//   lasd::StackLst<double> stacklst_double;
//   lasd::StackLst<float>  stacklst_float;
//   lasd::StackLst<string> stacklst_string;
//
//   if(sceltaVettList == 1) //Caso Vettore
//   {
//     if(dato == 1)
//     {
//       riempi(stackvec_int, n);
//     }
//     if(dato == 2)
//     {
//       riempi(stackvec_double, n);
//     }
//     if(dato == 3)
//     {
//       riempi(stackvec_float, n);
//     }
//     if(dato == 4)
//     {
//       riempi(stackvec_string, n);
//     }
//   }
//   if(sceltaVettList == 2) //Caso Lista
//   {
//     if(dato == 1)
//     {
//       riempi(stacklst_int, n);
//     }
//     if(dato == 2)
//     {
//       riempi(stacklst_double, n);
//     }
//     if(dato == 3)
//     {
//       riempi(stacklst_float, n);
//     }
//     if(dato == 4)
//     {
//       riempi(stacklst_string, n);
//     }
//   }
//
//   //Inizia il Menu di Stack
//   cout << "Benvenuto nello Stack - Menu" << endl;
//   cout << "1) Push " << endl;
//   cout << "2) Pop " << endl;
//   cout << "3) TopNPop" << endl;
//   cout << "4) Top" << endl;
//   cout << "5) Vuoto?" << endl;
//   cout << "6) Dimensione Stack" << endl;
//   cout << "7) Svuota Stack" << endl;
// }
// void Menu()
// {
//   int sceltaStruttura = 0;
//   int sceltaVettList  = 0;
//   int tipo = 0;
//   int n = 0;
//   cout << "Benvenuto nel MENU" << endl;
//   cout << "Scegli cosa utilizzare: " << endl;
//   cout << "1) Stack" << endl;
//   cout << "2) Queue" << endl;
//   cin  >> sceltaStruttura;
//   cout << endl;
//   cout << "Scegli tra Vettori o Liste" << endl;
//   cout << "1) Vettore" << endl;
//   cout << "2) Liste" << endl;
//   cin  >> sceltaVettList;
//   cout << endl;
//   cout << "Che tipo di dato vuoi utilizzare?" << endl;
//   cout << "1) Int" << endl;
//   cout << "1) Double" << endl;
//   cout << "1) Float" << endl;
//   cout << "1) String" << endl;
//   cin  >> tipo;
//   cout << "Quanti elementi vuoi inserire nella struttura?" << endl;
//   cin  >> n;
//
//   if(sceltaStruttura == 1)
//     MenuStack(tipo, sceltaVettList, n);
//   if(sceltaStruttura == 2)
//     //MenuQueue(tipo, sceltaVettList, n);
//
// }
