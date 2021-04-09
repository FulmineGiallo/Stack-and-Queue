
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec { // Must extend Stack<Data> and Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;

  // ...

public:

  // Default constructor
  // StackVec() specifier;

  /* ************************************************************************ */

  // Specific constructor
  // StackVec(argument) specifiers; // A stack obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  // StackVec(argument);

  // Move constructor
  // StackVec(argument);

  /* ************************************************************************ */

  // Destructor
  // ~StackVec() specifier;

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

  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  // type Push(argument) specifiers; // Override Stack member (move of the value)
  // type Top() specifiers; // Override Stack member (must throw std::length_error when empty)
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)

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
