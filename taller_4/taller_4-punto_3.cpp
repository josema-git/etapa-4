#include  <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class ListaStringsOptima{
    private:
        struct Nodo{
            Nodo* next[26];
            bool end;

            Nodo(){
                end = false;
            }
        } *head;


    public:

    ListaStringsOptima(){
        head = new Nodo();
    }

    void add(string val){ // esta funcion es O(n), con n = longitud de la palabra
        Nodo *temp = head; // O(1)
        transform(val.begin(), val.end(), val.begin(), ::tolower);
        for(char i : val){ // O(n)
            if(!temp->next[i-'a']){ // O(1)
                Nodo* nuevo_nodo = new Nodo(); // O(1)
                temp->next[i-'a'] = nuevo_nodo; // O(1)
            }
            temp = temp->next[i-'a']; // O(1)
        }
        temp->end = true; // O(1)
    }

    bool check(string val){ // esta funcion es O(n), con n = longitud de la palabra
        Nodo *temp = head; // O(1)
        transform(val.begin(), val.end(), val.begin(), ::tolower);
        for(char i : val){ // O(n)
            if(!temp->next[i-'a']){ // O(1)
                return false; // O(1)
            }
            temp = temp->next[i-'a']; // O(1)
        }
        return temp->end; // O(1)
    }

};

int main(){
    ListaStringsOptima lista;
    lista.add("manzana");
    lista.add("manaza");
    lista.add("arbol");
    lista.add("ahorro");
    lista.add("antes");
    lista.add("mesa");

    lista.check("manzana") ? cout << "manzana esta en la lista" << endl : cout << "manzana no esta en la lista" << endl;
    lista.check("arbol") ? cout << "arbol esta en la lista" << endl : cout << "arbol no esta en la lista" << endl;
    lista.check("perro") ? cout << "perro esta en la lista" << endl : cout << "perro no esta en la lista" << endl;
    lista.check("arbol")? cout << "arbol esta en la lista" << endl : cout << "arbol no esta en la lista" << endl;


    return 1;
}