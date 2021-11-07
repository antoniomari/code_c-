#ifndef CODA_VETT
#define CODA_VETT
# include "coda.cpp"
# include <iostream>

using namespace std;
template <class T>
class Coda_Vett : public Coda<T>
{
public:
    Coda_Vett();
    Coda_Vett(const Coda_Vett<T>&);
    ~Coda_Vett();
    void crea_coda();
    bool coda_vuota() const;
    T leggi_coda() const;
    void fuori_coda();
    void in_coda(T);

    void stampa_coda()
    {
        cout << "<- ";

        for(int i = 0; i < length; i++)
        {
            cout << vett[(head + i) % SIZE];
            if (i + 1 < length)
                cout << ", ";
        }
        cout << " <-\n";
    }

private:
    int SIZE = 4;
    T* vett;
    int head;
    int length;
};

//implementazione metodi

template <class T>
Coda_Vett<T>::Coda_Vett()
{
    crea_coda();
}

template <class T>
Coda_Vett<T>::Coda_Vett(const Coda_Vett<T>& p)
{
    SIZE = p.SIZE;
    head = p.head;
    vett = new T[SIZE];
    length = p.length;

    for(int i = 0; i < length; i++)
        vett[(head + i) % SIZE] = p.vett[(head + i) % SIZE];
}

template <class T>
Coda_Vett<T>::~Coda_Vett()
{
    delete[] vett;
}

template <class T>
void Coda_Vett<T>::crea_coda()
{
    vett = new T[SIZE];
    head = 0;
    length = 0;
}

template <class T>
bool Coda_Vett<T>::coda_vuota() const
{
    return length == 0;
}

template <class T>
T Coda_Vett<T>::leggi_coda() const
{
    //check PRE
    if(coda_vuota())
        throw invalid_argument("Coda vuota\n");

    return vett[head];
}

template <class T>
void Coda_Vett<T>::fuori_coda()
{
    //check PRE
    if(coda_vuota())
        throw invalid_argument("Coda vuota\n");

    head = (head + 1) % SIZE;
    length--;
}

template <class T>
void Coda_Vett<T>::in_coda(T new_elem)
{
    if(length == SIZE)
        throw invalid_argument("Impossibile aggiungere elementi: coda piena\n");
    vett[(head + length) % SIZE] = new_elem;
    length++;
}

#endif


