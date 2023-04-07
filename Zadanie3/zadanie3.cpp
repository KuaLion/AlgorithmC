#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    int punkty;
};

void sortowanieQuickSort(student* tab, int n, int tryb);
void wczytajStudentow(student*&tab, int n);
void usunTabliceStudentow(student *&tab);
void wyswietlStudentow(student* tab, int n);

int main() {
    string sciezka, linia, pomoc;
    int Liczbastudentow = 0;
    ifstream plik;
    char sredniki;
    student* tab;
    sciezka = "C:\\Users\\Kuba\\CLionProjects\\zadanie3\\studenci.csv"; //trzeba o sciezce pamietac

   plik.open(sciezka);
// sprawdzenie czy plik jest git
//   if(plik.good()) cout << "ok";
//   else cout << "zle";

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
   int tryb;
   cout << "Sortowanie Quicksort - wybierz 1 (rosnaco) lub 0 (malejaco)" << endl;
   cin >> tryb;
   wyswietlStudentow(tab, Liczbastudentow);
   sortowanieQuickSort(tab, Liczbastudentow, tryb);
   cout<< endl;
    wyswietlStudentow(tab, Liczbastudentow);
   usunTabliceStudentow(tab);
    return 0;
}


void sortowanieQuickSort(student* tab, int n, int tryb){
        int i = 0;
        int j = n - 1;
        int x = tab[(0 + n - 1) / 2].punkty;
        do {
            if(tryb == 1){ //rosnaco
                while (tab[i].punkty < x)
                    i++;
                while (tab[j].punkty > x)
                    j--;
            }
            else{ //malejaco
                while (tab[i].punkty > x)
                    i++;
                while (tab[j].punkty < x)
                    j--;
            }
            if(i<=j){
                swap(tab[i], tab[j]);
                i++;
                j--;
            }
        } while(i <=j); //rekurencja
            if (i < n) {
                sortowanieQuickSort(tab + i, n - i, tryb);
            }
            if (j > 0) {
                sortowanieQuickSort(tab, j + 1, tryb);
            }

}

void usunTabliceStudentow(student *&tab){
    delete []tab;
}

void wyswietlStudentow(student* tab, int n){
    for(int i=0; i< n; i++){
        cout<<"Imie: " << tab[i].imie << " Nazwisko: " << tab[i].nazwisko << " Liczba punktow: " << tab[i].punkty << endl;
    }
}