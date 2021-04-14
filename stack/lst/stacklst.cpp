
namespace lasd
{

/* ***************************************************************************/
template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& con)
{
  for(unsigned int i = 0; i < con.Size(); i++)
    Push(con[i]);
}
// Copy constructor
template <typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& newStack):List<Data>(newStack)
{
   testa = newStack.testa;
}
//move constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& newStack) noexcept
{
   std::swap(testa, newStack.testa);
}
// Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& newStack)
{
  List<Data>::operator=(newStack);
  return *this;
}
// Move assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& newStack) noexcept
{
  List<Data>::operator=(std::move(newStack));
  return *this;
}

template <typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& newStack) const noexcept
{
  /*
  if(size == newStack.size)
    return (*this == newStack);
  else
  */
    return false;
}

template <typename Data>
bool StackLst<Data>::operator!=(const StackLst<Data>& newStack) const noexcept
{

  //return !(*this == newStack);
  return false;
}

//Copy PUSH
template <typename Data>
void StackLst<Data>::Push(const Data& val)
{
  List<Data>::InsertAtFront(val);
}
//Move PUSH
template <typename Data>
void StackLst<Data>::Push(Data&& val) noexcept
{
    List<Data>::InsertAtFront(std::move(val));
}

template <typename Data>
Data& StackLst<Data>::Top() const
{
  if(testa == nullptr)
    throw std::length_error("Stack vuoto");
  else
    return testa->element;
}

template <typename Data>
void StackLst<Data>::Pop()
{
    List<Data>::RemoveFromFront();
}

template <typename Data>
Data StackLst<Data>::TopNPop()
{
  Data valueRemoved;
  valueRemoved = Top();
  Pop();
  return valueRemoved;
}

template <typename Data>
void StackLst<Data>::Clear()
{
  List<Data>::Clear();
}
/* ************************************************************************** */

}
