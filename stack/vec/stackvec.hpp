
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
  int indice = 0; //quando si richiama push --> indice ++, quando si richiama pop --> indice --;

public:

  // Default constructor
  StackVec() = default;

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
  ~StackVec();

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

  void Push(const Data& val) override; // Override Stack member (copy of the value) fare il test estensione
  void Push(Data&& val) noexcept; // Override Stack member (move of the value)
  /****************************************/

  Data& Top() const override; // Override Stack member (must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty) decrementa l'indice, senza cancellare, verà sovrascritto poi, fare il test riduzione
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member

  // type Size() specifiers; // Override Container member
  // type Clear() specifiers; // Override Container member

protected:
  // Auxiliary member functions

  // type Expand() specifiers;
  // type Reduce() specifiers;

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
