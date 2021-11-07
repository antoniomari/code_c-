#ifndef CODA_PUNT
#define CODA_PUNT

# include "coda.cpp"
# include <iostream>

using namespace std;
template <class T>
class Coda_Punt : public Coda<T>
{
public:
    Coda_Punt();
    Coda_Punt(const Coda_Punt<T>&);
    ~Coda_Punt();
    void crea_coda();
    bool coda_vuota() const;
    T leggi_coda() const;
    void fuori_coda();
    void in_coda(T);

    void stampa_coda()
    {
        cout << "<- ";

        for(auto temp = head; temp != nullptr; temp = temp->getSucc())
        {
            cout << temp->getElemento();
            if (temp->getSucc() != nullptr)
                cout << ", ";
        }
        cout << " <-\n";
    }

private:

    Cella<T>* head;
    Cella<T>* tail;
};

//implementazione metodi
template <class T>
Coda_Punt<T>::Coda_Punt()
{
    crea_coda();
}

template <class T>
Coda_Punt<T>::Coda_Punt(const Coda_Punt<T>& c)
{
    head = new Cella<T>;

    head->setElemento(c.head->getElemento());

    //puntatori temporanei per scorrere
    auto temp_old = c.head;
    auto temp_new = head;

    while(temp_old->getSucc() != nullptr)
    {
        temp_old = temp_old->getSucc();

        auto new_cella = new Cella<T>;
        new_cella->setElemento(temp_old->getElemento());
        temp_new->setSucc(new_cella);

        temp_new = temp_new->getSucc();
    }

    tail = temp_new;

}

template <class T>
Coda_Punt<T>::~Coda_Punt()
{
    auto temp = head;

    while(head != nullptr)
    {
        head = head->getSucc();
        delete temp;
        temp = head;
    }

}

template <class T>
void Coda_Punt<T>::crea_coda()
{
    head = nullptr;
    tail = nullptr;
}

template <class T>
bool Coda_Punt<T>::coda_vuota() const
{
    return head == nullptr;
}

template <class T>
T Coda_Punt<T>::leggi_coda() const
{
    //check PRE
    if(coda_vuota())
        throw invalid_argument("Coda vuota\n");

    return head->getElemento();
}

template <class T>
void Coda_Punt<T>::fuori_coda()
{
    //check PRE
    if(coda_vuota())
        throw invalid_argument("Coda vuota\n");

    auto temp = head;

    head = head->getSucc();

    delete temp;
}

template <class T>
void Coda_Punt<T>::in_coda(T new_elem)
{
    auto new_cella = new Cella<T>;

    new_cella->setElemento(new_elem);

    //se la coda è inizialmente vuota
    if(coda_vuota())
    {
        head = new_cella;
        tail = head;
    }
    else
    {
        tail->setSucc(new_cella);
        tail = new_cella;
    }
}

#endif
