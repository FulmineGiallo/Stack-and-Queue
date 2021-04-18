
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
  testa = newVec.testa;
  coda = newVec.coda;
  return *this;
}
//move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& newVec) noexcept
{
  Vector<Data>::operator=(std::move(newVec));
  testa = newVec.testa;
  coda = newVec.coda;
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
  if(coda % Vector<Data>::Size()  == testa)
    Expand();
    if(testa == coda)
    {
      Elements[testa] = std::move(val);
      coda++;
    }
  else
  {
    coda = ((coda) % Vector<Data>::Size());
    Elements[coda] = val;
    coda++;
  }
  sizeEffettiva++;
}

//move PUSH
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& val) noexcept
{
    if(coda % Vector<Data>::Size()  == testa)
      Expand();
    if(testa == coda)
    {
      Elements[testa] = std::move(val);
      coda++;
    }
    else
    {
      coda = ((coda) % Vector<Data>::Size());
      Elements[coda] = std::move(val);
      coda++;
    }
    sizeEffettiva++;
}

template <typename Data>
void QueueVec<Data>::Dequeue()
{
  if(sizeEffettiva == 0)
    throw std::length_error("Impossibile accedere al primo elemento di uno Coda vuoto!");
  else
  {
    testa = (testa) % Vector<Data>::Size();
    testa++;
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
  if(sizeEffettiva > 0)
    return Elements[testa];
  else
    throw std::length_error("Impossibile accedere al primo elemento di una Coda vuoto!");
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
  testa = 0;
  coda = 0;
  sizeEffettiva = 0;
}

template <typename Data>
void QueueVec<Data>::Expand()
{
  Vector<Data> v(size * 2);
  //Se testa parte da V[0]
  //Se coda + 1, = testa --> si deve Espandere il vettore con Expand()
  //Se testa == coda, vettore vuoto.
  //Se avessimo 0 1 2 3 --> vuoi inserire di nuovo in coda, quindi if(coda (mod) == Vectror<Data>::Size()) Exapand();
  //Quindi 0 1 2 3 4 5 6 7 --> 3 Dequeue() --> null null null 3 4 5 6 7

  //Copia il vecchio Elements nel nuovo v, e gestire gli indici
  int i = 0;
  for(unsigned int start = testa; start < Vector<Data>::Size(); start++)
  {
    v[i] = Elements[start];
    i++;
  }
  for(unsigned int start = coda; start < testa; start++)
  {
    v[i] = Elements[start];
    i++;
  }
  Vector<Data>::operator=(v);
  testa = 0;
  coda = sizeEffettiva;
  size = v.Size();
  v.Clear();

}
template <typename Data>
void QueueVec<Data>::Reduce()
{

}
/* ************************************************************************** */

}
