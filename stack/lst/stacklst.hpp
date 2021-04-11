
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst: virtual public Stack<Data>, virtual protected List<Data>
{

private:

  // ...

protected:

  using List<Data>::size; //riferimento a size, oppure ad altro
  using List<Data>::testa; //riferimento a testa per implementare lo stack

  //Nello stackLst, gli inserimenti Push() avvengono tramite InsertAtBack().
  //Nello stackLst, le  rimozioni    Pop()  avvengono tramite RemoveFromFront().

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
  StackLst(StackLst&&) noexcept;


  /* ************************************************************************ */
  // Destructor
   ~StackLst();

  /* ************************************************************************ */

  // Copy assignment
  bool operator=(const StackLst&);

  // Move assignment
  bool operator=(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst&) const noexcept;
  bool operator!=(const StackLst&) const noexcept;

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
