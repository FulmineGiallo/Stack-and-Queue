
namespace lasd
{

/* ************************************************************************** */
template<typename Data>
QueueVec<Data>::QueueVec() //costruttore senza parametri
{
  Vector<Data>::Resize(2);

}

template<typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& con)
{

}

//Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& newVec)
{
  Vector<Data>::operator=(newVec);
  index = newVec.index;
  sentinella = newVec.sentinella;
  return *this;
}
//move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& newVec) noexcept
{
  Vector<Data>::operator=(std::move(newVec));
  index = newVec.index;
  sentinella = newVec.sentinella;
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
   if(sentinella == (index + 1) % Vector<Data>::Size())
    //Expand();
   index = (index + 1) % Vector<Data>::Size();
   Elements[index] = val;

   sizeEffettiva++;
}

//move PUSH
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& val) noexcept
{
  if(sentinella == (index + 1) % Vector<Data>::Size())
  {
    //Expand();
  }
  index = (index + 1) % Vector<Data>::Size();
  Elements[index] = std::move(val);

  sizeEffettiva++;
}

template <typename Data>
void QueueVec<Data>::Dequeue()
{
  if(sizeEffettiva <= (Vector<Data>::Size() / 4))
  {

  }
  if(sizeEffettiva == 0)
    throw std::length_error("Impossibile accedere al primo elemento di uno Coda vuoto!");
  else
  {
    sentinella = (sentinella + 1) % Vector<Data>::Size();
    sizeEffettiva--;
  }

}

//TopNPop
template <typename Data>
Data QueueVec<Data>::HeadNDequeue()
{
  Data valueRemoved = Head();
  Dequeue();
  return valueRemoved;
}

template <typename Data>
Data& QueueVec<Data>::Head() const
{
  if(Size() > 0)
    return Elements[(sentinella + 1) % Vector<Data>::Size()];
  else
    throw std::length_error("Impossibile accedere al primo elemento di uno Coda vuoto!");
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
  if(sizeEffettiva == 0)
    return true;
  else
    return false;
}

template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept
{
  return sizeEffettiva;
}

template <typename Data>
void QueueVec<Data>::Clear()
{
  Vector<Data>::Clear();
  Vector<Data>::Resize(2);
  sentinella = 0;
  index = 0;
  sizeEffettiva = 0;
}

template <typename Data>
void QueueVec<Data>::Expand()
{
  Vector<Data> v;
  v.Resize(size * 2);
  //Se testa parte da V[0]
  //Se coda + 1, = testa --> si deve Espandere il vettore con Expand()
  //Se testa == coda, vettore vuoto.
  //Se avessimo 0 1 2 3 --> vuoi inserire di nuovo in coda, quindi if(coda (mod) == Vectror<Data>::Size()) Exapand();
  //Quindi 0 1 2 3 4 5 6 7 --> 3 Dequeue() --> null null null 3 4 5 6 7 
}
template <typename Data>
void QueueVec<Data>::Reduce()
{

}
/* ************************************************************************** */

}
