
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: virtual public Stack<Data>, virtual protected Vector<Data>
{

private:

  // ...

protected:

  using Vector<Data>::size;
  using Vector<Data>::Elements;
  int indice = 0;  //quando si richiama push --> indice ++, quando si richiama pop --> indice --;
  int sentinella = 0;

public:

  // Default constructor
  StackVec(); //DONE

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const LinearContainer<Data>& con); // A stack obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec&);

  // Move constructor
  StackVec(StackVec&&) noexcept;

  /* ************************************************************************ */
  // Destructor
  ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  bool operator=(const StackVec&);

  // Move assignment
  bool operator=(StackVec&&) noexcept;

  /* ************************************************************************ */
  // Comparison operators
  bool operator==(const StackVec&) const noexcept;
  bool operator!=(const StackVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  void Push(const Data& val) override; // Override Stack member (copy of the value) fare il test estensione DONE
  void Push(Data&& val) noexcept override; // Override Stack member (move of the value)
  /****************************************/

  Data& Top() const override; // Override Stack member (must throw std::length_error when empty) DONE
  void Pop() override; // Override Stack member (must throw std::length_error when empty) decrementa l'indice, senza cancellare, verà sovrascritto poi, fare il test riduzione DONE
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty) DONE

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() override; // Override Container member

  unsigned long Size() override; // Override Container member
  void Clear() override; // Override Container member

protected:
  // Auxiliary member functions

  void Expand(); // è void, perchè puoi stackvec.Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
