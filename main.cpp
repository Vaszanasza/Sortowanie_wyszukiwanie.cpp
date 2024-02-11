#include <iostream>
#include "sort.hpp"
#include "search.hpp"

using namespace std;

const int SIZE = 10;

int main() {
    int t[SIZE];
    wypelnij_tablice(t, SIZE);

    cout << "Tablica przed sortowaniem: ";
    wydrukuj_tablice(t, SIZE);

    sortowanie_babelkowe(t, SIZE);
    cout << "Tablica po sortowaniu bąbelkowym: ";
    wydrukuj_tablice(t, SIZE);

    wypelnij_tablice(t, SIZE);
    sortowanie_przez_wstrzasanie(t, SIZE);
    cout << "Tablica po sortowaniu przez wstrząsanie: ";
    wydrukuj_tablice(t, SIZE);

    wypelnij_tablice(t, SIZE);
    sortowanie_przez_scalanie(t, SIZE);
    cout << "Tablica po sortowaniu przez scalanie: ";
    wydrukuj_tablice(t, SIZE);

    wypelnij_tablice(t, SIZE);
    sortowanie_szybkie(t, SIZE);
    cout << "Tablica po sortowaniu szybkim: ";
    wydrukuj_tablice(t, SIZE);

    int t_out[SIZE] = {};
    wypelnij_tablice(t, SIZE);
    sortowanie_przez_wstawianie(t, SIZE, t_out);
    cout << "Tablica po sortowaniu przez wstawianie: ";
    wydrukuj_tablice(t_out, SIZE);

    int key = 55;

    cout << "Wyszukiwanie liniowe: ";
    cout << wyszukiwanie_liniowe(t, SIZE, key) << endl;

    cout << "Wyszukiwanie liniowe z wartownikiem: ";
    cout << wyszukiwanie_liniowe_z_wart(t, SIZE, key) << endl;

    cout << "Wyszukiwanie skokowe: ";
    cout << wyszukiwanie_skokowe(t, SIZE, key) << endl;

    cout << "Wyszukiwanie binarne: ";
    cout << wyszukiwanie_binarne(t, SIZE, key) << endl;

    cout << "Wyszukiwanie interpolacyjne: ";
    cout << wyszukiwanie_interpolacyjne(t, SIZE, key) << endl;

    return 0;
}
