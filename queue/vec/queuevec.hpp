
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: virtual public Queue<Data>, virtual protected Vector<Data>
{ // Must extend Queue<Data> and Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::size;
  using Vector<Data>::Elements;
  int testa = 0;
  int coda  = 0;
  // ...
  //si parte da 1, cosi abbiamo la pos 0 come sentinella per il resize

public:

  // Default constructor
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const LinearContainer<Data>& con); // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec<Data>& newQueue);

  // Move constructor
  QueueVec(QueueVec<Data>&& newQueue) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueVec<Data>& operator=(const QueueVec<Data>& newQueue);

  // Move assignment
  QueueVec<Data>& operator=(QueueVec<Data>&& newQueue) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec<Data>& newQueue) const noexcept;
  bool operator!=(const QueueVec<Data>& newQueue) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  void Enqueue(const Data& val) override; // Override Queue member (copy of the value)
  void Enqueue(Data&& val) noexcept override; // Override Queue member (move of the value)
  Data& Head() const override; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override; // Override Container member
  unsigned long Size()  const noexcept override; // Override Container member
  void Clear() override; // Override Container member

protected:

  // Auxiliary member functions

  // type Expand() specifiers;
  // type Reduce() specifiers;
  // type SwapVectors(arguments) specifiers;

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
