
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack { // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Stack() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Push(argument) specifiers; // Copy of the value
  // type Push(argument) specifiers; // Move of the value
  // type Top() specifiers; // (concrete function must throw std::length_error when empty)
  // type Pop() specifiers; // (concrete function must throw std::length_error when empty)
  // type TopNPop() specifiers; // (concrete function must throw std::length_error when empty)

};

/* ************************************************************************** */

}

#endif
