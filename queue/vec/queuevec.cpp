
namespace lasd
{

/* ************************************************************************** */
template<typename Data>
QueueVec<Data>::QueueVec() //costruttore senza parametri
{
  Vector<Data>::Resize(1);
}

template<typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& con)
{

}

//Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& newVec)
{
  

  return *this;
}
//move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& newVec) noexcept
{

  return *this;
}

//Copy constructor
template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& newVec):Vector<Data>(newVec)
{

  //la size la fa nel costruttore di vector<int> v;
}

//move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& vec) noexcept
{

}


//Copy PUSH
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& val)
{

}

//move PUSH
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& val) noexcept
{

}

template <typename Data>
void QueueVec<Data>::Dequeue()
{

}

//TopNPop
template <typename Data>
Data QueueVec<Data>::HeadNDequeue()
{
  Data valueRemoved;
  valueRemoved = Head();
  return valueRemoved;
}

template <typename Data>
Data& QueueVec<Data>::Head() const
{
  if(Size() > -1)
    return Elements[0];
  else
    throw std::length_error("Impossibile accedere al primo elemento di uno stack vuoto!");
}


//operator ==
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& newVec) const noexcept
{

  return false;
}
//operator !=
template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec<Data>& newVec) const noexcept
{
  return false;
}

template <typename Data>
bool QueueVec<Data>::Empty() const noexcept
{

    return false;
}

template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept
{
  return 1;
}

template <typename Data>
void QueueVec<Data>::Clear()
{
  Vector<Data>::Clear();
  Vector<Data>::Resize(1);

}
/* ************************************************************************** */

}
