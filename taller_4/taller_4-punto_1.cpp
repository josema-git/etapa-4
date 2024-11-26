#include  <iostream>
#include <unordered_map>

using namespace std;

class ListaStrings{
    private:
        struct Nodo{
            string val;
            Nodo* next;
            Nodo(){val = ""; next = NULL;}
            Nodo(string val){this->val = val; next = NULL;}
        } *head;


    public:

    ListaStrings(){
        head = NULL;
    }

    ~ListaStrings(){
        Nodo*temp = head;
        while(temp){
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void add(string val){ // esta funcion es O(n)
        Nodo* nuevo_nodo = new Nodo(val); // O(1) 
        if(!head){ // O(1)
            head = nuevo_nodo; // O(1)
        }else{
            Nodo* temp = head; // O(1)
            while(temp->next){ // O(n)
                temp = temp->next; // O(1)
            }
            temp->next = nuevo_nodo; // O(1)
        }
    }

    bool check(string val){ // esta funcion es O(n)
        Nodo* temp = head; // O(1)
        while(temp){ // O(n)
            if (temp->val == val){ // O(1)
                return true; // O(1)
            }
            temp = temp->next; // O(1)
        }
        return false; // O(1)
    }

};

int main(){
    ListaStrings lista;
    lista.add("manzana");
    lista.add("arbol");
    lista.add("zorro");
    lista.add("elefante");
    lista.add("casa");

    lista.check("manzana") ? cout << "manzana esta en la lista" << endl : cout << "manzana no esta en la lista" << endl;
    lista.check("arbol") ? cout << "arbol esta en la lista" << endl : cout << "arbol no esta en la lista" << endl;
    lista.check("perro") ? cout << "perro esta en la lista" << endl : cout << "perro no esta en la lista" << endl;

    return 1;
}