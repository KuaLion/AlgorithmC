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

int zad71();
void zad72(int Liczbastudentow);
void zad73(int Liczbastudentow);

student *tab;

//do zadania 7.2
//void wyszliniowe(tab, n, wartosc);
//void wyszbi(tab, n, wartosc);

int main() {
    int wybor;
    cout << "Wybierz zadanie: " << endl;
    cout << "1 - zadanie 7.1" << endl;
    cout << "2 - zadanie 7.2" << endl;
    cout << "3 - zadanie 7.3" << endl;
    cout << "4 - wyjscie" << endl;
    cin >> wybor;
        switch(wybor){
            case 1:{
                zad71(); break;
            }
            case 2:{
                zad71();
                int Liczbastudentow = zad71();
                zad72(Liczbastudentow);
                break;
            }
            case 3: {
                zad71();
                int Liczbastudentow = zad71();
                zad73(Liczbastudentow);
                break;
            }
            case 4: break;
            default: break;
        }

    return 0;
}

int zad71(){
// wczytanie z pliku
    string sciezka, linia, pomoc;
    int Liczbastudentow = 0;
    ifstream plik;
    char sredniki;
    //student* tab;
    sciezka = "studenci1.csv"; //trzeba o sciezce pamietac
    //sciezka = "C:\\Users\\pcmin\\Documents\\Studia\\studenci1.csv"; //trzeba o sciezce pamietac
//    if(plik.good()) cout << "ok";
//   else cout << "zle";
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


void zad72(int Liczbastudentow){
    int dane;
    int licznik = 0;
    cout << "Podaj liczbe punktow: " << endl;
    while(dane < 0){
        cout << "Podaj liczbe wieksza od 0" << endl;
    }
    cin >> dane;
    for(int i=0;i <Liczbastudentow; i++){
        if(tab[i].punkty == dane){
            cout << "Imie: " << tab[i].imie << "Nazwisko: " << tab[i].nazwisko << " Liczba punkty: " << tab[i].punkty << endl;
            licznik++;
        }
    }
    if(licznik == 0){
        cout << "Brak studentow o podanej liczbie punktow";
    }
}

void zad73(int Liczbastudentow){
    int dane;
    int licznik = 0;
    cout << "Podaj liczbe punktow: " << endl;
    while(dane < 0){
        cout << "Podaj liczbe wieksza od 0" << endl;
    }
    cin >> dane;
    int lewy = 0;
    int prawy = Liczbastudentow-1;
    while(lewy<=prawy){
        int srodek = (lewy + prawy)/2;
        if(tab[srodek].punkty == dane){
            cout << srodek << endl;
            licznik++;
        }
        else{
            if(dane <tab[srodek].punkty){
                prawy = srodek - 1;
            }
            else{
                lewy = srodek + 1;
            }
        }
    }
    if(licznik ==0){
        cout << "Brak studenta o podanej ilosci punktow" << endl;
    }
    ofstream zapis;
    string sciezkaDoZapisu="wyniki.csv";
    zapis.open(sciezkaDoZapisu);
    zapis<<Liczbastudentow<<endl;
    for(int i=0; i<Liczbastudentow; i++)
    {zapis<<tab[i].imie<<";"<<tab[i].nazwisko<<";";
        zapis<<tab[i].punkty<<endl; }
     zapis.close();
}

//
//void wyszliniowe(tab, n, wartosc){
//    for(int i=0;i <n; i++){
//        if(tab[i] == wartosc){
//            cout << i << endl;
//        }
//    }
//}
//
//void wyszbi(tab, n, wartosc){
//    int lewy = 0;
//    int prawy = n-1;
//    while(lewy<=prawy){
//        int srodek = (lewy + prawy)/2;
//        if(tab[srodek] == wartosc){
//            cout << srodek << endl;
//        }
//        else{
//            if(wartosc<tab[srodek]){
//                prawy = srodek - 1;
//            }
//            else{
//                lewy = srodek + 1;
//            }
//        }
//    }
//}