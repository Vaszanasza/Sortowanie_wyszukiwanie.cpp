#include "sort.hpp"
#include <iostream>
#include <cmath>

using namespace std;

void wypelnij_tablice(int tab[], int size) {
    for (int i = 0; i < size; ++i) {
        tab[i] = rand() % 70; 
    }
}

void wydrukuj_tablice(int tab[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void sortowanie_babelkowe(int tab[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (tab[j] > tab[j + 1]) {
                swap(tab[j], tab[j + 1]);
            }
        }
    }
}

void sortowanie_przez_wstrzasanie(int tab[], int size) {
    bool zamiana = true;
    int lewy = 0;
    int prawy = size - 1;
    
    while (zamiana) {
        zamiana = false;
        for (int i = lewy; i < prawy; ++i) {
            if (tab[i] > tab[i + 1]) {
                swap(tab[i], tab[i + 1]);
                zamiana = true;
            }
        }
        if (!zamiana)
            break;
        zamiana = false;
        --prawy;
        for (int i = prawy; i >= lewy; --i) {
            if (tab[i] > tab[i + 1]) {
                swap(tab[i], tab[i + 1]);
                zamiana = true;
            }
        }
        ++lewy;
    }
}

void scalanie(int tab[], int lewy, int srodek, int prawy) {
    int n1 = srodek - lewy + 1;
    int n2 = prawy - srodek;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = tab[lewy + i];
    for (int j = 0; j < n2; ++j)
        R[j] = tab[srodek + 1 + j];

    int i = 0, j = 0, k = lewy;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tab[k] = L[i];
            ++i;
        }
        else {
            tab[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        tab[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        tab[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void sortowanie_przez_scalanie_recursive(int tab[], int lewy, int prawy) {
    if (lewy < prawy) {
        int srodek = lewy + (prawy - lewy) / 2;
        sortowanie_przez_scalanie_recursive(tab, lewy, srodek);
        sortowanie_przez_scalanie_recursive(tab, srodek + 1, prawy);
        scalanie(tab, lewy, srodek, prawy);
    }
}

void sortowanie_przez_scalanie(int tab[], int size) {
    sortowanie_przez_scalanie_recursive(tab, 0, size - 1);
}

int partition(int tab[], int low, int high) {
    int pivot = tab[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (tab[j] < pivot) {
            ++i;
            swap(tab[i], tab[j]);
        }
    }
    swap(tab[i + 1], tab[high]);
    return i + 1;
}

void sortowanie_szybkie_recursive(int tab[], int low, int high) {
    if (low < high) {
        int pi = partition(tab, low, high);
        sortowanie_szybkie_recursive(tab, low, pi - 1);
        sortowanie_szybkie_recursive(tab, pi + 1, high);
    }
}

void sortowanie_szybkie(int tab[], int size) {
    sortowanie_szybkie_recursive(tab, 0, size - 1);
}

void sortowanie_przez_wstawianie(int tab[], int size, int tab_out[]) {
    for (int i = 0; i < size; ++i) {
        int klucz = tab[i];
        int j = i - 1;
        while (j >= 0 && tab_out[j] > klucz) {
            tab_out[j + 1] = tab_out[j];
            --j;
        }
        tab_out[j + 1] = klucz;
    }
}
