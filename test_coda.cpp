//
// Created by 39347 on 28/10/2021.
//

#include <iostream>
#include "coda_rappr_puntatori.cpp"
#include "coda_rappr_vettore.cpp"

using namespace std;

int main(){

    // RAPPRESENTAZIONE VETTORE
    Coda_Vett<double> p;


    p.in_coda(1.5);
    p.stampa_coda();

    p.in_coda(3.5);
    p.stampa_coda();

    p.in_coda(4.5);
    p.stampa_coda();

    p.in_coda(2.5);
    p.stampa_coda();

    p.fuori_coda();
    p.stampa_coda();

    p.fuori_coda();
    p.stampa_coda();

    p.in_coda(10);
    p.stampa_coda();

    p.fuori_coda();
    p.stampa_coda();

    p.fuori_coda();
    p.stampa_coda();

    p.fuori_coda();
    p.stampa_coda();


    // RAPPRESENTAZIONE PUNTATORI
    Coda_Punt<double> p1;


    p1.in_coda(1.5);
    p1.stampa_coda();

    p1.in_coda(3.5);
    p1.stampa_coda();

    p1.in_coda(4.5);
    p1.stampa_coda();

    p1.in_coda(2.5);
    p1.stampa_coda();

    p1.fuori_coda();
    p1.stampa_coda();

    p1.fuori_coda();
    p1.stampa_coda();

    p1.in_coda(10);
    auto p2(p1);
    p1.stampa_coda();

    p1.fuori_coda();
    p1.stampa_coda();

    p1.fuori_coda();
    p1.stampa_coda();

    p1.fuori_coda();
    p1.stampa_coda();

    p2.stampa_coda();

    return 0;
}