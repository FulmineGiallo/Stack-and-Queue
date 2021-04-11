
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst
{ // Must extend public:Stack<Data>(virtuale) and protected:List<Data>

private:

  // ...

protected:

  // using List<Data>::size; riferimento a size, oppure ad altro
  // using List<Data>::testa; riferimento a testa per implementare lo stack

public:

  // Default constructor, senza parametri.
  StackLst() = default;

  // StackLst() specifier;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const LinearContainer<Data>& con);

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst&);

  // Move constructor
  StackLst(StackLst&&) noexcpet;


  /* ************************************************************************ */
  // Destructor
   ~StackLst();

  /* ************************************************************************ */

  // Copy assignment
  bool operator=(const StackLst&);

  // Move assignment
  bool operator=(StackLst&&) noexcpet;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst&) const noexcpet;
  bool operator!=(const StackLst&) const noexcpet;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  //metodi pubblici, fare ovverride
  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  // type Push(argument) specifiers; // Override Stack member (move of the value)
  // type Top() specifiers; // Override Stack member (must throw std::length_error when empty)
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  // non ci sarà motivo di fare l'ovveride di empty e size

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
