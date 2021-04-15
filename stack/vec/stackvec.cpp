
namespace lasd
{

/* ************************************************************************** */
template<typename Data>
StackVec<Data>::StackVec() //costruttore senza parametri
{
  Vector<Data>::Resize(1);
}

template<typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& con)
{
  Vector<Data>::Resize(con.Size());
  unsigned int sizeReal = con.Size();
  for(unsigned int i = sizeReal; i > 0; i--)
    Push(con[i - 1]);
  //return non serve perchè, stai riempiendo la classe dell'oggetto attuale istanziato.
}
//Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& newVec)
{
  Vector<Data>::operator=(newVec);
  indice = newVec.indice;
  sentinella = newVec.sentinella;
  return *this;
}
//move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& newVec) noexcept
{
  Vector<Data>::operator=(std::move(newVec));
  std::swap(indice, newVec.indice);
  std::swap(sentinella, newVec.sentinella);
  return *this;
}

//Copy constructor
template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& newVec):Vector<Data>(newVec)
{
  indice = newVec.indice;
  sentinella = newVec.sentinella;
  //la size la fa nel costruttore di vector<int> v;
}

//move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& vec) noexcept
{
    std::swap(Elements, vec.Elements);
    std::swap(indice, vec.indice);
    std::swap(sentinella, vec.sentinella);
    std::swap(size, vec.size);
}


//Copy PUSH
template <typename Data>
void StackVec<Data>::Push(const Data& val)
{
  if(sentinella == size - 1)
    Expand();
  if(sentinella == 0)
  {
    Elements[sentinella] = val;
    sentinella++; // == 1
    //index == 0;
  }
  else
  {
    Elements[sentinella] = val;
    indice++;
    sentinella++;
  }
}

//move PUSH
template <typename Data>
void StackVec<Data>::Push(Data&& val) noexcept
{
  if(sentinella == size - 1)
  {
    Expand();
  }
  if(sentinella == 0)
  {
    Elements[sentinella] = std::move(val);
    sentinella++; // == 1
    //index == 0;
  }
  else
  {
    Elements[sentinella] = std::move(val);
    indice++;
    sentinella++;
  }
}

template <typename Data>
void StackVec<Data>::Pop()
{
  if(sentinella == (size/2))
  {
    Reduce();
  }

  if(sentinella == 0)
  {
    throw std::length_error("impossibile effettuare pop su stack vuoto!");
  }
  else
  {
    indice--;
    sentinella--;
  }
}

//TopNPop
template <typename Data>
Data StackVec<Data>::TopNPop()
{
  Data valueRemoved = Top();
  Pop();
  return valueRemoved;
}

template <typename Data>
Data& StackVec<Data>::Top() const
{
  if(sentinella > 0)
    return Elements[indice];
  else
    throw std::length_error("Impossibile accedere al primo elemento di uno stack vuoto!");
}

template <typename Data>
void StackVec<Data>::Expand()
{
    Vector<Data>::Resize(size * 2);
}
template <typename Data>
void StackVec<Data>::Reduce()
{
    Vector<Data>::Resize(size - (size / 4));
}
//operator ==
template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& newVec) const noexcept
{
  return Vector<Data>::operator==(newVec);
}
//operator !=
template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& newVec) const noexcept
{
  return !(Vector<Data>::operator==(newVec));
}

template <typename Data>
bool StackVec<Data>::Empty() const noexcept
{
  if(sentinella == 0)
    return true;
  else
    return false;
}

template <typename Data>
unsigned long StackVec<Data>::Size() const noexcept
{
  return sentinella;
}

template <typename Data>
void StackVec<Data>::Clear()
{
  Vector<Data>::Clear();
  sentinella = 0;
  indice = 0;
}
/* ************************************************************************** */

}
