#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


struct element{
    int number;
    element* next;
};
void push(element *& ,int value);
void pop(element *&);
bool puste(element *);
int top(element *);
void czyszczenie(element*&);
int main()
{
    srand(time(NULL));
    element* Stack = nullptr;
    element* temp = nullptr;
    int choice;
    int jestok = 1;
    bool stop;

do{
    cout << "Wybierz operacje: " << endl
         << "1 - zadanie 1" << endl
         << "2 - zadanie 2" << endl
         << "3 - zadanie 3" << endl
         << "4 - zadanie 4" << endl
         << "5 - zadanie 5" << endl
         << "6 - wyjscie z programu" << endl;
        cin >> choice;
    switch(choice){
        case 1:{
            if(puste(Stack) == 1){
                cout << "Stos jest pusty" << endl;
            }
            else{
                cout << "Stos nie jest pusty" << endl;
            }
            break;
        }
        case 2:{
            int special = (rand() % 10) + 1;
            push(Stack,special);
            cout << "Do stosu zosta³a dodana liczba " << special << endl;
            break;
        }
        case 3:{
            if(puste(Stack) == 1){
                cout << "Stos jest pusty" << endl;
            }
            else{
                pop(Stack);
            }
            break;
        }
        case 4:{
            int ostatni = top(Stack);
            if(ostatni != -1){
                cout << "Element na stosie wynosi: " << ostatni << endl;
            }
            else{
                cout << "Stos jest pusty" << endl;
            }
            break;
        }
        case 5:{
            stop = false;
            while(!stop){
                if(!puste(Stack)){
                    pop(Stack);
                }
                else stop = true;
            }
            cout << "Wszystkie elementy stosu zostaly usuniete" << endl;
            break;
            /*int n = 0;
            while(stack){
                n++;
                stack = stack->next;
            }
            for(int i =0; i <n;i++){
                pop(stack);
            } */
            break;
        }
        case 6:{
            delete Stack;
            jestok = 1;
            break;
        }
        default:{
            break;
        }
    }
}while(jestok != 0);

    return 0;
}

void push(element *&Stack, int value){
    element* newel = new element;
    newel -> number = value;
    newel -> next = Stack;
    Stack = newel;
}
void pop(element *&Stack){
    if(!puste(Stack)){
        element* temp = Stack;
        Stack = Stack->next;
        delete temp;
}
}
bool puste(element *Stack){
    if(Stack == nullptr){
        return 1;
    }
    else{
        return 0;
    }
}
int top(element *Stack){
    if(puste(Stack)){
        cout << "Stos jest pusty ";
        return -1;
    }
        return Stack->number;
}
void czyszczenie(element *& Stack){
    while(!puste(Stack)) pop(Stack);
}
