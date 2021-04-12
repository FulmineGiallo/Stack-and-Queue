
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack: virtual public Container
{

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
  bool operator=(const Stack<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  bool operator=(Stack<Data>&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Stack<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Stack<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  void Push(const Data& val); // Copy of the value
  void Push(Data&& val) noexcept; // Move of the value
  /*****************************************************/
  Data& Top() const = 0; // (concrete function must throw std::length_error when empty)
  void  Pop(); // (concrete function must throw std::length_error when empty)
  Data  TopNPop(); // (concrete function must throw std::length_error when empty)

};

/* ************************************************************************** */

}

#endif
