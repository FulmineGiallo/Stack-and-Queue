
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst{ // Must extend public:Stack<Data>(virtuale) and protected:List<Data>

private:

  // ...

protected:

  // using List<Data>::???; riferimento a size, oppure ad altro

  // ...

public:

  // Default constructor, senza parametri.

  // StackLst() specifier;

  /* ************************************************************************ */

  // Specific constructor
  // StackLst(argument) specifiers; // A stack obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  // StackLst(argument);

  // Move constructor
  // StackLst(argument);

  /* ************************************************************************ */

  // Destructor
  // ~StackLst() specifier;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);

  // Move assignment
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

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
