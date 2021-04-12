
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackVec<Data>::StackVec() //costruttore senza parametri
{
  Elements = new Data[1];
  size = 1;

}

template<typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& con)
{
  for(unsigned int i = 0; i < con.Size(); i++)
    /*this.*/Push(con[i]);
  //return non serve perchè, stai riempiendo la classe dell'oggetto attuale istanziato.
}

//Copy constructor
template<typename Data>
StackVec<Data>::StackVec(const StackVec& newVec)
{

  StackVec<Data> tmp;
  Data val;
  if(newVec.size >= 1)
  {
    for(unsigned int i = 0; i < newVec.Size(); i++)
      tmp.Push(newVec.TopNPop());
    for(unsigned int i = 0; i < newVec.Size(); i++)
    {
      val = tmp.TopNPop();
      /*this*/Push(val);
      newVec.Push(val);
    }
    Resize(newVec.Size());
  }
}

//move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec&& vec) noexcept
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
  if(indice == 0 && sentinella == 0)
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
  if(size != 0)
    return Elements[indice];
  else
    throw std::length_error("Impossibile accedere al primo elemento di uno stack vuoto!");
}

template <typename Data>
void StackVec<Data>::Expand()
{
    Resize(size * 2);
}

template <typename Data>
void StackVec<Data>::Reduce()
{
    Resize(size - (size / 4));
}

/* ************************************************************************** */

}
