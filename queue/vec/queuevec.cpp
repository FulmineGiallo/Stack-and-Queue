
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
  sizeEffettiva = con.Size();
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

}

//move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& newVec) noexcept
{
  std::swap(Elements, newVec.Elements);
  std::swap(testa, newVec.testa);
  std::swap(coda, newVec.coda);
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
  int x;
  if(sizeEffettiva == newVec.sizeEffettiva)
  {
    Vector<Data> v1(sizeEffettiva);
    Vector<Data> v2(sizeEffettiva);
    int j = 0;
    if(coda < testa)
    {
      for(int i = testa; i < Vector<Data>::Size(); i++)
      {
        v1[j] = Elements[i];
        j++;
      }
      for(int i = (coda - 1); i < testa; i++)
      {
        v1[j] = Elements[i];
        j++;
      }
    }
    j = 0;
    if(coda > testa)
    {
      for(int i = testa; i < coda; i++)
      {
        v1[j] = Elements[i];
        j++;
      }
    }
    j = 0;
    if(newVec.coda < newVec.testa)
    {
      for(unsigned int i = newVec.testa; i < newVec.size; i++)
      {
        v2[j] = newVec.Elements[i];
        j++;
      }

      for(int i = (newVec.coda - 1); i < newVec.testa; i++)
      {
        v2[j] = newVec.Elements[i];
        j++;
      }
    }
    j = 0;
    if(newVec.coda > newVec.testa)
    {
      for(int i = newVec.testa; i < newVec.coda; i++)
        {
          v2[j] = newVec.Elements[i];
          j++;
        }
    }

    x = (v1 == v2);
    v1.Clear();
    v2.Clear();
    if(x==0)  return false;
    else      return true;
  }
  else
    return false;
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
  if(coda < testa)
  {
    for(unsigned int start = testa; start < Vector<Data>::Size(); start++)
    {
      v[i] = Elements[start];
      i++;
    }
    for(unsigned int start = 0; start < coda; start++)
    {
      v[i] = Elements[start];
      i++;
    }
  }
  i = 0;
  if( coda > testa)
    for(unsigned int start = testa; start < coda; start++)
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
    i = 0;
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
