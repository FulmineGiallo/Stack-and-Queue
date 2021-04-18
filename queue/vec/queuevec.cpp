
namespace lasd
{

/* ************************************************************************** */
template<typename Data>
QueueVec<Data>::QueueVec() //costruttore senza parametri
{
  Vector<Data>::Resize(2);

}

template<typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& con):Vector<Data>::Vector(con)
{
  testa = 0;
  coda = con.Size();
  sizeEffettiva = con.Size() - 1;
}

//Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& newVec)
{
  Vector<Data>::operator=(newVec);
  testa = newVec.testa;
  coda = newVec.coda;
  sizeEffettiva = newVec.sizeEffettiva;
  return *this;
}
//move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& newVec) noexcept
{
  Vector<Data>::operator=(std::move(newVec));
  testa = newVec.testa;
  coda = newVec.coda;
  sizeEffettiva = newVec.sizeEffettiva;
  return *this;
}

//Copy constructor
template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& newVec):Vector<Data>(newVec)
{
  testa = newVec.testa;
  coda  = newVec.coda;
  sizeEffettiva = newVec.sizeEffettiva;
  //la size la fa nel costruttore di vector<int> v;
}

//move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& newVec) noexcept
{
  std::swap(Elements, newVec.Elements);
  std::swap(testa, newVec.testa);
  std::swap(coda, newVec.testa);
  std::swap(sizeEffettiva, newVec.sizeEffettiva);

}


//Copy PUSH
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& val)
{
    if(sizeEffettiva == Vector<Data>::Size())
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
    if(sizeEffettiva == Vector<Data>::Size())
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
  //Aggiungere il Reduce();
  if(sizeEffettiva == size / 2)
  {
    Reduce();
  }
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
  if(sizeEffettiva != newVec.sizeEffettiva)
    return false;
  else
    return true;

}
//operator !=
template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec<Data>& newVec) const noexcept
{
  return !(*this == newVec);
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
  Vector<Data> v(size - (size / 4));
  int i = 0;
  if(coda < Vector<Data>::Size())
  {
    for(unsigned int start = testa; start < Vector<Data>::Size(); start++)
    {
      v[i] = Elements[start];
      i++;
    }
  }
  else
  {
    for(unsigned int start = coda; start < testa; start++)
    {
      v[i] = Elements[start];
      i++;
    }
  }

  Vector<Data>::operator=(v);
  testa = 0;
  coda = sizeEffettiva;
  size = v.Size();
  v.Clear();
}
/* ************************************************************************** */

}
