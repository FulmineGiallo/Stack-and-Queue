
namespace lasd {

/* ************************************************************************** */
//Copy constructor
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& newQueue)
{
  testa = newQueue.testa;
  coda  = newQueue.coda;
}

//Move constructor
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& newQueue) noexcept
{
  testa = std::move(newQueue.testa);
  coda =  std::move(newQueue.coda);
}

//Copy assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& newQueue)
{
  List<Data>::operator=(newQueue);
  return *this;
}
//Move assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& newQueue)
{
  List<Data>::operator=(std::move(newQueue));
  return *this;
}

// Comparison operators ==
template <typename Data>
bool operator==(const QueueLst<Data>& newQueue) const noexcept
{
  return List<Data>::operator==(newQueue);
}
// Comparison operators !=
template <typename Data>
bool operator!=(const QueueLst<Data>& newQueue) const noexcept
{
  return !(*this == newQueue);
}

//Copy PUSH
template <typename Data>
void QueueLst<Data>::Enqueue(const Data& val)
{
  List<Data>::InsertAtBack(val);
}
//Move PUSH
template <typename Data>
void QueueLst<Data>::Enqueue(Data&& val)
{
  List<Data>::InsertAtBack(std::move(val));
}

template <typename Data>
Data& QueueLst<Data>::Head() const
{
  return List<Data>::Front();
}

template <typename Data>
void QueueLst<Data>::Dequeue()
{
  List<Data>::RemoveFromFront();
}

template <typename Data>
Data QueueLst<Data>::HeadNDequeue()
{
  Data valueRemoved;
  valueRemoved = Head();
  Dequeue();
  return valueRemoved;
}

template <typename Data>
void QueueLst<Data>::Clear()
{
  List<Data>::Clear();
}
/* ************************************************************************** */

}
