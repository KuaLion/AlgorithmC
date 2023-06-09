#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct element{
    char literka;
    element* next;
};

void push(element *&Stack, string literka);
void pop(element *&Stack);
bool puste(element *Stack);
char top(element *Stack);
void wczytaj(element *& literka);
void zapis(element *tekst);

int main()
{
    /*/ wczytanie pliku
    string wiersz, n;
    ifstream plik, pliktemp;
    plik.open("znaki1.txt");
    pliktemp.open("znaki1.txt");
    /* if(plik.good()) cout << "ok";
    else cout << "zle";
    while(getline(plik,wiersz)){
        n += wiersz;
    }
    // stos
    int rozmiar = n.length();
    element* tekst = nullptr;
    for(int i=0;i <rozmiar;i++){
        push(stack, i);
    }
    while(puste(stack)!= 1){
        for(int i =0;i<rozmiar;i++){
        top(stack);
        cout << number;
        }
    } */
    element* tekst = nullptr;
    cout << "Wczytanie z pliku znaki1.txt" << endl;
    wczytaj(tekst);
    cout << "Odwrocenie kolejnosci w pliku wyniki.txt" << endl;
    zapis(tekst);
    return 0;
}

void push(element *&Stack, int literka){
    element* newel = new element;
    newel -> literka = literka;
    newel -> next = Stack;
    Stack = newel;
}

void pop(element *&Stack){
    if(puste(Stack)){
        cout << "Stos jest pusty";
        //return 0;
    }
    element* temp = Stack;
    Stack = Stack->next;
    delete temp;
}

bool puste(element *Stack){
    if(Stack == nullptr){
        return 1;
    }
    else{
        return 0;
    }
}
char top(element *Stack){
    if(puste(Stack)){
        cout << "Stos jest pusty ";
        return 0;
    }
        return Stack->literka;
}

void wczytaj(element *& literka){
    ifstream plik, pliktemp;
    char sym;
    pliktemp.open("znaki1.txt");
    plik.open("znaki1.txt");
    int dlugosc = 0;
    while (pliktemp.get(sym)) dlugosc++;
    pliktemp.close();
    int i = 0;
    while (plik.get(sym) && i < dlugosc){
        push(literka, sym);
        i++;
    }
    plik.close();
}
void zapis(element *tekst){
    ofstream zapis;
    zapis.open("wyniki.txt");
    bool stop = false;
    while(!stop){
        if(!puste(tekst)){
            zapis << top(tekst);
            pop(tekst);
        }
        else stop = true;
    }
    zapis.close();
}
