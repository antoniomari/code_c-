#ifndef CODA_ASTRACT
#define CODA_ASTRACT
# include "cella.cpp"
template<class T>
class Coda
{
public:
    virtual void crea_coda() = 0;
    virtual bool coda_vuota() const = 0;
    virtual T leggi_coda() const = 0;
    virtual void fuori_coda() = 0;
    virtual void in_coda(T) = 0;
};

#endif