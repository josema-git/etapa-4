#include <iostream>

using namespace std;

template <typename T>
void imprimir(T* array, int tamaño){
    cout << "-------------------------------------------------------------" <<endl;
    for(int i = 0; i < tamaño; i++ ){
        cout << "Elemento en la posicion " << i << ": " <<  array[i] << endl;
    }
    cout << "-------------------------------------------------------------" <<endl<<endl;
}

template <typename T>
T* bubbleSort(T* array, int tamaño){
    for (int i = 0; i < tamaño; i++){
        for(int j = 0; j < tamaño-i-1 ; j++){ // empezamos siempre desde la primera palabra y vamos hasta el indice n-i, poniendo siempre al final la mas grande
            if (array[j] < array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
    return array;
}

int main (){
    char array[7];
    array[5] = 'a';
    array[3] = 'b';
    array[4] = 'c';
    array[1] = 'd';
    array[0] = 'e';
    array[2] = 'f';
    array[6] = 'g';
    int tamaño = sizeof(array) / sizeof(array[0]);

    char copia[tamaño];
    copy(&array[0], &array[7], &copia[0]);
    imprimir(bubbleSort(copia, tamaño), tamaño);
    imprimir(array, tamaño);
    
    return 1;
}