#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct element{
    char znak;
    element* next;
};
struct kolejka{
    element *head;
    element *tail;
};

void push(kolejka &k, char value);
void pop(kolejka &k);
bool puste(kolejka k);
char pierwszy(kolejka k);
void wczytaj(kolejka &k);
void wyswietl(kolejka &k);

int main()
{
    kolejka k;
    k.head = nullptr;
    k.tail = nullptr;

    bool jestok = true;
    int choice;
    char tempznak;
    do{
        cout << "Wybierz zadanie: " << endl
             << "1 - zadanie 1 " << endl
             << "2 - zadanie 2 " << endl
             << "3 - zadanie 3 " << endl
             << "4 - zadanie 4 " << endl
             << "5 - zadanie 5 " << endl
             << "6 - zadanie 6 " << endl
             << "7 - Wyswietl kolejka (sprawdzenie) " << endl
             << "8 - wyjdz z programu " << endl;
        cin >> choice;

        switch(choice){
            case 1:{
                if(puste(k)){
                    cout << "Kolejka jest pusta" << endl;
                }
                else{
                    cout << "Kolejka nie jest pusta" << endl;
                }
                break;
            }
            case 2:{
                cout << "Podaj element, ktory chcesz dodac do kolejki" << endl;
                cin >> tempznak;
                push(k, tempznak);
                break;
            }
            case 3:{
                if(!puste(k)){
                    pop(k);
                    cout << "Element kolejki zostal usuniety" << endl;
                }
                else{
                    cout << "Kolejka jest pusta" << endl;
                }
                break;
            }
            case 4:{
                if(!puste(k)){
                    cout << "Pierwszy element kolejki: " << pierwszy(k) << endl;
                }
                else{
                    cout << "Kolejka jest pusta" << endl;
                }
                break;
            }
            case 5:{
                if(!puste(k)){
                    cout << "Usuniete elementy: ";
                    while(true){
                        if(!puste(k)){
                            cout << pierwszy(k) << " ";
                            pop(k);
                        }
                        else break;
                    }
                    cout << endl;
                }
                else{
                    cout << "Kolejka jest pusta" << endl;
                }
                break;
            }
            case 6:{
                wczytaj(k);
                cout << "Wczytane duze litery z pliku znaki2.txt" << endl;
                break;
            }
            case 7:{
                if(puste(k)){
                    cout << "Kolejka jest pusta" << endl;
                }
                else{
                    wyswietl(k);
                }
                break;
            }
            case 8:{
                jestok = false;
                break;
            }
            default:{
                system("cls");
                break;
            }
        }
    }while(jestok!=false);

    return 0;
}

void push(kolejka &k, char value){
    element *el = new element;
    el->znak=value;
    el->next=nullptr;
    if(k.tail !=nullptr){
        k.tail->next=el;
    }
    else k.head = el;
    k.tail=el;
}

void pop(kolejka &k){
    element *temp = k.head;
    k.head=k.head->next;
    delete temp;
    if(k.head==nullptr){
        k.tail = nullptr;
    }
}

bool puste(kolejka k){
    if(k.head == nullptr) return true;
    return false;
}

char pierwszy(kolejka k){
    if(puste(k)){
        return '\0';
    }
    return k.head->znak;
}

void wczytaj(kolejka &k){
    ifstream plik;
    char sym;
    plik.open("znaki2.txt");
    while(plik.get(sym)){
        if((65 <= sym) && (90 >= sym)){
            push(k, sym);
        }
    }
    plik.close();
}

void wyswietl(kolejka &k){
    kolejka nowa;
    nowa.head = nullptr;
    nowa.tail = nullptr;
    char symbol;
    cout << "Kolejka: ";
    while(!puste(k)){
        symbol = pierwszy(k);
        cout << symbol << " ";
        push(nowa, symbol);
        pop(k);
    }
    cout << endl;
    k = nowa;
}
