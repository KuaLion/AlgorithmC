#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void zad51();
void zad52();
void zad53();
void zad54();

//do zadania 2
void al_naiwny(string, string, int, int, int*);
//do zadania 3
void tablicadopasowan(string, int, int*);
void kmp(string, string, int, int, int *, int*);
// do zadania 4
void tablicaprzesuniec(string, int, int*, int, int);
void bm(string,string,int,int,int*, int, int*);


int main() {
    int wybor;
    bool koniec = false;
    while (!koniec) {
        cout << "Wybierz zadanie:" << endl;
        cout << "1 - zadanie 5.1" << endl;
        cout << "2 - zadanie 5.2" << endl;
        cout << "3 - zadanie 5.3" << endl;
        cout << "4 - zadanie 5.4" << endl;
        cout << "5 - Wyjscie z programu" << endl;
        cin >> wybor;

        switch (wybor) {
            case 1:
                zad51();
                break;
            case 2:
                zad52();
                break;
            case 3:
                zad53();
                break;
            case 4:
                zad54();
                break;
            case 5:
                koniec = true;
                break;
            default: break;
        }
    }
    return 0;
}

void zad51(){
    string wzorzec;
    string tekst;
    cout << "Wprowadz tekst" << endl;
    string temp;
    cin >> temp;
    getline(cin,tekst);
    tekst = temp + tekst;
    //   cin.ignore();
//    getline(cin, tekst);
    cout << "Wprowadz wzorzec" << endl;
    cin >> temp;
    getline(cin,wzorzec);
    wzorzec = temp + wzorzec;
    //    cin.ignore();
//   getline(cin, wzorzec);
    int dlt = tekst.length();
    int dlw = wzorzec.length();
    cout << "Dlugosc tekstu wynosi " << dlt << endl;
    cout << "Dlugosc wzorca wynosi " << dlw << endl;
}
// dlt dlugosc tekstu, dlw dlugosc wzorca
void zad52(){
//    for(int i =0; i <dlt-dlw;i++){
//        for(int j = 0; j<dlw && wzorzec[j]==tekst[i+j]; j++){
//            if (j==dlw) cout << i << endl;
//        }
//    }
    string wzorzec; // wczytanie danych
    string tekst;
    cout << "Wprowadz tekst" << endl;
    string temp;
    cin >> temp;
    getline(cin,tekst);
    tekst = temp + tekst;
    //    cin.ignore();
//    getline(cin, tekst);
    cout << "Wprowadz wzorzec" << endl;
    cin >> temp;
    getline(cin,wzorzec);
    wzorzec = temp + wzorzec;
    //    cin.ignore();
//    getline(cin, wzorzec);
    cout << endl;
    int dlt = tekst.length();
    int dlw = wzorzec.length();

    if(dlt < dlw){ //sprawdzenie poprawnej dlugosci
        cout << "Podany wzorzec jest dluzszy niz tekst" << endl;
        return;
    }
    //wypisanie danych
//    for(int i =0; i < dlt;i++) {
//        cout << tekst[i] << " | ";
//    }
//    cout << endl ;

//    for(int i =0; i < dlt; i++) {
//        cout << i << " | ";
//    }
    cout << tekst << endl;
    cout << wzorzec << endl;
    cout << endl;

    int *index = new int[dlt-dlw+1];
    al_naiwny(tekst, wzorzec, dlt, dlw, index);
    for(int i =0; i<=dlt;i++){
        int j = 0;
        while((j <=dlw) and (tekst[i+j] == wzorzec[j])){
            j++;
            if(j==dlw){
                for(int k=0;k<i;k++){
                    cout << " ";
                    cout << wzorzec<<endl;
                }
            }
        }
    }
    cout << endl;

}

void zad53(){
    string wzorzec; // wczytanie danych
    string tekst;
    cout << "Wprowadz tekst" << endl;
    string temp;
    cin >> temp;
    getline(cin,tekst);
    tekst = temp + tekst;
    //cin.ignore();
    //getline(cin, tekst);
    cout << "Wprowadz wzorzec" << endl;
    cin >> temp;
    getline(cin,wzorzec);
    wzorzec = temp + wzorzec;
//    cin.ignore();
//    getline(cin, wzorzec);
    //cout << endl;
    int dlt = tekst.length();
    int dlw = wzorzec.length();

    if(dlt < dlw){ //sprawdzenie poprawnej dlugosci
        cout << "Podany wzorzec jest dluzszy niz tekst" << endl;
        return;
    }
//    cout <<"| ";
//    for(int i = 0;i< dlt;i++){
//        cout << tekst[i] << " | ";
//    }
//    cout << endl << "| ";
//    for(int i = 0; i < dlt; i++){
//        cout << i << " | ";
//    }
    cout << tekst << endl;
    cout << wzorzec << endl;
    cout << endl;

    int *p = new int[dlt-dlw+1];
    int *index = new int[dlt-dlw+2];
    tablicadopasowan(wzorzec, dlw, p);

    kmp(wzorzec, tekst, dlw, dlt, p , index);
    for(int i =0; i<=dlt;i++){
        int j = 0;
        while((j <=dlw) and (tekst[i+j] == wzorzec[j])){
            j++;
            if(j==dlw){
                for(int k=0;k<i;k++){
                    cout << " ";
                    cout << wzorzec<<endl;
                }
            }
        }
    }
    cout << endl;

}

void zad54(){
    string wzorzec; // wczytanie danych
    string tekst;
    cout << "Wprowadz tekst" << endl;
    string temp;
    cin >> temp;
    getline(cin,tekst);
    tekst = temp + tekst;
    //    cin.ignore();
//    getline(cin, tekst);
    cout << "Wprowadz wzorzec" << endl;
    cin >> temp;
    getline(cin,wzorzec);
    wzorzec = temp + wzorzec;
    //    cin.ignore();
//    getline(cin, wzorzec);
    cout << endl;
    int dlt = tekst.length();
    int dlw = wzorzec.length();

    if(dlt < dlw){ //sprawdzenie poprawnej dlugosci
        cout << "Podany wzorzec jest dluzszy niz tekst" << endl;
        return;
    }
//    cout <<"| ";
//    for(int i = 0;i< dlt;i++){
//        cout << tekst[i] << " | ";
//    }
//    cout << endl << "| ";
//    for(int i = 0; i < dlt; i++){
//        cout << i << " | ";
//    }
    cout << tekst << endl;
    cout << wzorzec << endl;
    cout << endl;

    int *p = new int[dlt-dlw+1];
    int *index = new int[dlt-dlw+2];
    tablicadopasowan(wzorzec, dlw, p);

    tablicaprzesuniec(wzorzec, dlw, p, tekst[0], tekst[dlt]);

    bm(wzorzec, tekst, dlw, dlt, p ,tekst[0], index);
    for(int i =0; i<=dlt;i++){
        int j = 0;
        while((j <=dlw) and (tekst[i+j] == wzorzec[j])){
            j++;
            if(j==dlw){
                for(int k=0;k<i;k++){
                    cout << " ";
                    cout << wzorzec<<endl;
                }
            }
        }
    }
    cout << endl;

}

void al_naiwny(string tekst, string wzorzec, int dlt, int dlw, int *index){
    int r = -1;
    for(int i = 0; i <= dlt- dlw; i++){
        int j = 0;
        while(j<dlw && wzorzec[j] == tekst[i+j]) j++;
        if(j==dlw){
            index[r+1] = i;
            r++;
        }
    }
    index[dlt-dlw] = r;
}

void tablicadopasowan(string wzorzec, int dlw, int *p){ //ze schematu ns
    p[0] = 0;
    p[1] = 0;
    int t = 0;
    for(int i = 1; i <dlw; i++){
        while(t>0 && wzorzec[t]!=wzorzec[i]){
            t = p[t];
        }
        if (wzorzec[t] == wzorzec[i]){
            t++;
        }
        p[i+1]=t;
    }
}

void kmp(string wzorzec, string tekst, int dlw, int dlt, int *p, int *index){
    int i = 0;
    int j = 0;
    int r = -1;
    while(i < dlt - dlw +1){
        while((wzorzec[j] == tekst[i+j]) && (j < dlw))
            j++;
        if (j == dlw){
            index[r+1] = i;
            r++;
        }
        i = i + max(1, j-p[j]);
        j = p[j];
    }
    index[dlt-dlw+1] = r;
}

void tablicaprzesuniec(string wzorzec, int dlw, int*p, int poczatek, int koniec){
    int start = poczatek;
    int end = koniec;
    for(int i=0;i <=end-start;i++) p[i] = -1;
    for(int i =0; i < dlw; i++) p[wzorzec[i] - start] = i;
}

void bm(string wzorzec, string tekst, int dlw ,int dlt, int *p, int poczatek, int *index){
    int r = -1;
    int start = poczatek;
    int j;
    for(int i = 0; i <=dlt-dlw;){
        j = dlw-1;
        while((j>-1) && (wzorzec[j] == tekst[i+j])) j--;
        if (j == -1){
            index[r+1] = i;
            r++;
            i++;
        }
        else {
            i = i + max(1, j - p[tekst[i + j] - start]);
        }
    }
    index[dlt-dlw+1] = r;
}
