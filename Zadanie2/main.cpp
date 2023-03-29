#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void przydzielPamiec1D(int *&tab, int n);
void przydzielPamiec2D(int **&tab, int w, int k);
void wypelnijTablice1D(int *tab, int n, int a, int b);
void wypelnijTablice2D(int **tab, int w, int k, int a, int b);
void usunTablice1D(int *&tab);
void usunTablice2D(int **&tab, int w);
void wyswietl1D(int* tab, int n);
void wyswietl2D(int** tab, int w, int k);

void sortowanieBabelkowe(int* tab, int n, int tryb);
void sortowaniePrzezWybor(int* tab, int n, int tryb);
void sortowaniePrzezWstawianie(int* tab, int n, int tryb);
void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol);

void zad22();
void zad23();
void zad24();
void zad25();

int main()
{
    int wybor;
        cout << "1) zadanie 2.2" << endl;
        cout << "2) zadanie 2.3" << endl;
        cout << "3) zadanie 2.4" << endl;
        cout << "4} zadanie 2.5" << endl;
        cout << "5) wyjscie z programu" << endl;
        cout << "Wybierz opcje" << endl;
        cin >> wybor;
        switch (wybor){
            case 1: zad22(); break;
            case 2: zad23(); break;
            case 3: zad24(); break;
            case 4: zad25(); break;
            case 5: exit(0); break;
            default: main();
        }
        return 0;
}

void zad22(){
 int n, a ,b, tryb = 0;
 cout << "Podaj rozmiar tablicy";
 cin >> n;
 cout << "Podaj przedzial <a,b>";
 cin >> a;
 cin >> b;
 cout << "Podaj tryb sortowania (rosnaco - 1, malejaco - 0)";
 cin >> tryb;
 int *tablica = nullptr;
 przydzielPamiec1D(tablica, n);
 wypelnijTablice1D(tablica, n, a, b);
 wyswietl1D(tablica, n);
 sortowanieBabelkowe(tablica, n, tryb);
 cout << endl;
 wyswietl1D(tablica, n);
 usunTablice1D(tablica);
}

void zad23(){
int n, a ,b, tryb;
  cout << "Podaj rozmiar tablicy";
  cin >> n;
  cout << "Podaj przedzial <a,b>";
  cin >> a;
  cin >> b;
  cout << "Podaj tryb sortowania (rosnaco - 1, malejaco - 0)";
  cin >> tryb;
  int *tablica = nullptr;
  przydzielPamiec1D(tablica, n);
  wypelnijTablice1D(tablica, n, a, b);
  wyswietl1D(tablica, n);
  sortowaniePrzezWybor(tablica, n, tryb);
  cout << endl;
  wyswietl1D(tablica, n);
  usunTablice1D(tablica);
}

void zad24(){
int n, a ,b, tryb;
  cout << "Podaj rozmiar tablicy";
  cin >> n;
  cout << "Podaj przedzial <a,b>";
  cin >> a;
  cin >> b;
  cout << "Podaj tryb sortowania (rosnaco - 1, malejaco - 0)";
  cin >> tryb;
  int *tablica = nullptr;
  przydzielPamiec1D(tablica, n);
  wypelnijTablice1D(tablica, n, a, b);
  wyswietl1D(tablica, n);
  sortowaniePrzezWstawianie(tablica, n, tryb);
  cout << endl;
  wyswietl1D(tablica, n);
  usunTablice1D(tablica);
}

void zad25(){
 int n, w, k, a, b, tryb, nrkolumny;
 cout << "Podaj rozmiar tablicy (Wiersze, kolumny)";
 cin >> w;
 cin >> k;
 cout << "Podaj przedzial <a, b>";
 cin >> a;
 cin >> b;
 cout << "Podaj tryb sortowania (rosnaco - 1, malejaco - 0)";
 cin >> tryb;
 cout << "Podaj numer kolumny";
 cin >> nrkolumny;
 int **tablica = nullptr;
 przydzielPamiec2D(tablica, w ,k);
 wypelnijTablice2D(tablica, w, k ,a, b);
 wyswietl2D(tablica, w, k);
 sortowanieBabelkowe2D(tablica, w, k, tryb, nrkolumny);
 cout << endl;
 wyswietl2D(tablica, w, k);
 usunTablice2D(tablica, w);
}

void przydzielPamiec1D(int *&tab, int n) {
	tab = new int[n];
}

void przydzielPamiec2D(int **&tab, int w, int k) {
	tab = new int * [w]; //w to wymiar tablicy
	for(int i=0;i<w;i++) {
		tab[i] = new int[k];
	}
}

void wypelnijTablice1D(int *tab, int n, int a, int b) {
	srand(time(NULL));
	for(int i = 0; i<n; i++) {
		int liczba = rand()%(b-a+1)+a;
		tab[i] = liczba;
	}
}

void wypelnijTablice2D(int **tab, int w, int k, int a, int b) {
	srand(time(NULL));
	for(int i =0;i<w;i++) {
		for(int j=0;j<k;j++) {
			int liczba2 = rand()%(b-a+1)+a;
			tab[i][j] = liczba2;
		}
	}
}

void wyswietl1D(int* tab, int n){
	for(int i=0;i<n;i++)
	{
		cout<<tab[i]<<",";
	}
}
void usunTablice1D(int *&tab) {
	delete []tab;
}

void wyswietl2D(int** tab, int w, int k)
{
    for (int i=0;i<w;i++)
    {
        for (int j=0;j<k;j++)
        {
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void usunTablice2D(int **&tab, int w){
    for(int i=0;i<w;i++){
		delete [] tab[i];
    }//niedokonca wiem jak dziala usuwanie tablicy 2 wymiarowej
	delete [] *tab;
}


void sortowanieBabelkowe(int* tab, int n, int tryb){
    if(tryb == 1){
        for(int i=0; i<n; i++){
            for(int j = 0; j<n-1; j++){
                if(tab[i]<tab[j]){
                    swap(tab[j], tab[i]);
                }
            }
        }
    }
    else{
        for(int i=0; i<n; i++){
            for(int j = 0; j<n-1; j++){
                if(tab[i]>tab[j]){
                    swap(tab[i], tab[j]);
                }
            }
        }
    }
}



void sortowaniePrzezWybor(int* tab, int n, int tryb) {
    if (tryb == 1) {
        int ind = 0;
        for (int i = 0; i < n; i++) {
            ind = i;
            for (int j = i + 1; j < n; j++) {
                if (tab[j] < tab[ind]) {
                    ind = j;
                }
            }
            swap(tab[ind], tab[i]);
        }
    }
    else{
        int ind = 0;
        for (int i = 0; i < n; i++) {
            ind = i;
            for (int j = i + 1; j < n; j++) {
                if (tab[j] > tab[ind]) {
                    ind = j;
                }
            }
            swap(tab[i], tab[ind]);
        }
    }
}


void sortowaniePrzezWstawianie(int* tab, int n, int tryb){
	if(tryb == 1){
        int temp, j;
        for(int i = 1; i<n;i++){
            temp = tab[i];
            for(j = i -1; j >=0 && tab[j] > temp;j--){
                tab[j+1] = tab[j];
            }
            tab[j+1] = temp;
        }
    }
    else{
        int temp, j;
        for(int i = 1; i<n;i++){
            temp = tab[i];
            for(j = i -1; j >=0 && tab[j] < temp; j--){
                tab[j + 1] = tab[j];
            }
            tab[j + 1] = temp;
        }
    }
}

void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol) {
    if (tryb == 1) {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < w-1; j++) {
                if (tab[j][nrKol] < tab[j+1][nrKol]) {
                    for(int k =0;k<w;k++) {
                        swap(tab[j][k], tab[j+1][k]);
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < w-1; j++) {
                if (tab[j][nrKol] > tab[j+1][nrKol]) {
                    for(int k =0;k<w;k++) {
                        swap(tab[j][k], tab[j+1][k]);
                    }
                }
            }
        }
    }
}