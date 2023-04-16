#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct student {
    string imie;
    string nazwisko;
    int punkty;
};

int zad41();
void zad42(int Liczbastudentow);
void zad43(int Liczbastudentow);

void wyswietlStudentow(student* tab, int n);
student* tab;


int main() {
    int wybor;
    cout << "Wybierz zadanie" << endl;
    cout << "1 - Zadanie 4.1" << endl;
    cout << "2 - Zadanie 4.2" << endl;
    cout << "3 - Zadanie 4.3" << endl;
    cin >> wybor;
    switch (wybor) {
        case 1: zad41(); break;
        case 2:
        {
            zad41();
            int Liczbastudentow = zad41();
            zad42(Liczbastudentow);
        }break;
        case 3:{
            zad41();
            int Liczbastudentow = zad41();
            zad43(Liczbastudentow);
        }break;
    }
    return 0;
}

int zad41(){
    // wczytanie z pliku
    string sciezka, linia, pomoc;
    int Liczbastudentow = 0;
    ifstream plik;
    char sredniki;
//    student* tab;
    sciezka = "C:\\Users\\Kuba\\Documents\\Studia\\Semestr 2\\Podstawy algorytmiki\\laby\\4\\studenci.csv"; //trzeba o sciezce pamietac

    plik.open(sciezka);
    plik >> Liczbastudentow; // wczytanie liczby studentow
    cout << Liczbastudentow << endl;
    for(int i =0; i<2;i++){
        plik >> sredniki;
    }
    tab = new student[Liczbastudentow];
    for(int i = 0; i<Liczbastudentow; i++){
        plik >> linia;
        stringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty = atoi(pomoc.c_str());}
    plik.close();
    return Liczbastudentow;
}


void zad42(int Liczbastudentow){
    // wyswietlenie tablicy
    wyswietlStudentow(tab, Liczbastudentow);
    // podzial na 2 zbiory
    int i = 0;
    int j= Liczbastudentow - 1;
    while(i < j){
        while (tab[i].punkty <= 10 && i < j) i++;
        while (tab[i].punkty > 10 && i < j) j--;
        if (i < j) {
            swap(tab[i], tab[j]);
        }
    }
    cout << endl;
    // wyswietlenie po podziale
    cout << "Studenci, ktorzy otrzymali <= 10 punktow" << endl;
    for(i = 0; i < Liczbastudentow; i++){
        if(tab[i].punkty <= 10) cout << "Imie: " << tab[i].imie << " Nazwisko: " << tab[i].nazwisko << " Liczba punktow: " << tab[i].punkty << endl;
    }
    cout << endl;
    cout << "Studenci, ktorzy otrzymali > 10 punktow" << endl;
    for(i = 0; i < Liczbastudentow; i++){
        if(tab[i].punkty > 10) cout << "Imie: " << tab[i].imie << " Nazwisko: " << tab[i].nazwisko << " Liczba punktow: " << tab[i].punkty << endl;
    }
}

void zad43(int Liczbastudentow){
    //wyswietlenie studentow
    wyswietlStudentow(tab, Liczbastudentow);
    cout << endl;
    // podzial na 3
    int i = -1;
    int j = 0;
    int k = Liczbastudentow;
    while (j<k){
        if(tab[j].punkty <= (tab[j].punkty % 3 == 1)){
            i++;
            swap(tab[i], tab[j]);
            j++;
        }
        else{
            if(tab[j].punkty> (tab[j].punkty % 3 == 2)){
                k--;
                swap(tab[j], tab[j]);
            }
            else{
                j++;
            }
        }
    }

    // wyswietlenie po podziale
    cout << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3:" << endl;
    for(i = 0; i < Liczbastudentow; i++){
        if(tab[i].punkty % 3 == 0) cout << "Imie: " << tab[i].imie << " Nazwisko: " << tab[i].nazwisko << " Liczba punktow: " << tab[i].punkty << endl;
    }
    cout << endl;
    cout << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 1:" << endl;
    for(i = 0; i < Liczbastudentow; i++){
        if(tab[i].punkty % 3 == 1) cout << "Imie: " << tab[i].imie << " Nazwisko: " << tab[i].nazwisko << " Liczba punktow: " << tab[i].punkty << endl;
    }
    cout << endl;
    cout << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 2:" << endl;
    for(i = 0; i < Liczbastudentow; i++){
        if(tab[i].punkty % 3 == 2) cout << "Imie: " << tab[i].imie << " Nazwisko: " << tab[i].nazwisko << " Liczba punktow: " << tab[i].punkty << endl;
    }
}

void wyswietlStudentow(student* tab, int n){
    for(int i=0; i< n; i++){
        cout<<"Imie: " << tab[i].imie << " Nazwisko: " << tab[i].nazwisko << " Liczba punktow: " << tab[i].punkty << endl;
    }
}