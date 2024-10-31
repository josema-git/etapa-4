#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void imprimir(T *array, int length)
{
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "Elemento en la posicion " << i << ": " << array[i] << endl;
    }
    cout << "-------------------------------------------------------------" << endl
         << endl;
}

// bubble sort

template <typename T>
T *bubbleSort(T *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        { // empezamos siempre desde la primera palabra y vamos hasta el indice n-i, poniendo siempre al final la mas grande
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
    return array;
}

// selecction sort

template <typename T>
T *selecctionSort(T *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        int indexDesordenados = i;
        for (int j = i; j < length; j++)
        {
            if (array[indexDesordenados] > array[j])
            {
                indexDesordenados = j;
            }
        }
        swap(array[i], array[indexDesordenados]);
    }
    return array;
}

// busqueda binaria

template <typename T>
int binarySearch(T *array, int inicio, int final, T objetivo)
{
    if (inicio > final)
        return -1;
    int mitad = (final + inicio) / 2;
    if (array[mitad] == objetivo)
        return mitad;
    else if (objetivo < array[mitad])
        return binarySearch(array, inicio, mitad - 1, objetivo);
    else
        return binarySearch(array, mitad + 1, final, objetivo);
}

// merge sort

void merge(int arr[], int start, int middle, int end)
{
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int start, int end)
{
    if (end > start)
    {                                           // if we have subarrays at least with 1 elements each one
        int middle = start + (end - start) / 2; // index where we are going to separate the array

        mergeSort(arr, start, middle);   // creating the left subarray
        mergeSort(arr, middle + 1, end); // creating the right sub-array

        int n1 = middle - start + 1;
        int n2 = end - middle;

        vector<int> izquierda(n1);
        vector<int> derecha(n2);

        for (int i = 0; i < n1; i++)
            izquierda[i] = arr[start + i];

        for (int j = 0; j < n2; j++)
            derecha[j] = arr[middle + 1 + j];

        int i = 0, j = 0, k = start; // index i will be for

        while (i < n1 && j < n2)
        {
            if (izquierda[i] <= derecha[j])
            {
                arr[k] = izquierda[i];
                i++;
            }
            else
            {
                arr[k] = derecha[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = izquierda[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = derecha[j];
            j++;
            k++;
        }
    }
}
int main()
{
    // array unordered
    int n = 6;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = n - i;
    }
    int length = (int)sizeof(array) / sizeof(array[0]);

    // bubble sort
    int bubble_sort_array[n];
    copy(&array[0], &array[n], &bubble_sort_array[0]);
    bubbleSort(bubble_sort_array, length);
    imprimir(bubble_sort_array, length);

    // selecction sort
    int selecction_sort_array[n];
    copy(&array[0], &array[n], &selecction_sort_array[0]);
    selecctionSort(selecction_sort_array, length);
    imprimir(selecction_sort_array, length);

    // binary search

    int numero_busqueda = 4;
    cout << "resultado busqueda binaria: " << binarySearch(selecction_sort_array, 0, length, numero_busqueda) << endl
         << endl;

    // merge sort

    int merge_sort_array[n];
    copy(&array[0], &array[n], &merge_sort_array[0]);
    mergeSort(merge_sort_array, 0, length - 1);
    imprimir(merge_sort_array, length);

    return 1;
}