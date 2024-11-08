#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;


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

template <typename T>
void mergeSort(T arr[], int start, int end)
{
    if (end > start)
    {                                           // if we have subarrays at least with 1 elements each one
        int middle = start + (end - start) / 2; // index where we are going to separate the array

        mergeSort(arr, start, middle);   // creating the left subarray in each iteration
        mergeSort(arr, middle + 1, end); // creating the right sub-array in each iteration

        int n1 = middle - start + 1; // size of the left subarray
        int n2 = end - middle;       // size of the right subarray

        vector<int> izquierda(n1); // creating the left subarray in this iteration
        vector<int> derecha(n2);   // creating the right subarray in this iteration

        for (int i = 0; i < n1; i++)
            izquierda[i] = arr[start + i]; // asigning the values to the left subarray

        for (int j = 0; j < n2; j++)
            derecha[j] = arr[middle + 1 + j]; // asigning the values to the right subarray

        int i = 0, j = 0, k = start; // i is the index for the left subarray, j is the index for the right subarray and k is the index for the combined array

        while (i < n1 && j < n2)
            (izquierda[i] <= derecha[j]) ? arr[k++] = izquierda[i++] : arr[k++] = derecha[j++]; // comparing the values of the left and right subarrays and adding the values to the combined array in order

        while (i < n1)
            arr[k++] = izquierda[i++]; // adding the remaining values of the left subarray to the combined array

        while (j < n2)
            arr[k++] = derecha[j++]; // adding the remaining values of the right subarray to the combined array
    }
}

// quick sort

template <typename T>
void quickSort(T array[], int inicio, int final)
{
    if (inicio > final) return;
    int pivote = array[final];
    int i = inicio - 1;
    for (int j = inicio; j < final; j++)
        if (array[j] < pivote)
            swap(array[++i], array[j]);
    swap(array[i + 1], array[final]);
    quickSort(array, inicio, i);
    quickSort(array, i + 2, final);
}

// count sort

void countSort(int array[], int size) {
  // Find the largest element of the array
  int max = array[0];

  // Find the largest element of the array
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Dynamically allocate count and output arrays
  vector<int> output(size);
  vector<int> count(max + 1, 0);

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

int main()
{
    // array unordered
    int n = 50000;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = n - i;
    }
    int length = (int)sizeof(array) / sizeof(array[0]);

    // bubble sort
    // int bubble_sort_array[n];
    // copy(&array[0], &array[n], &bubble_sort_array[0]);
    // bubbleSort(bubble_sort_array, length);
    // imprimir(bubble_sort_array, length);

    // // selecction sort
    // int selecction_sort_array[n];
    // copy(&array[0], &array[n], &selecction_sort_array[0]);
    // selecctionSort(selecction_sort_array, length);
    // imprimir(selecction_sort_array, length);

    // // binary search

    // int numero_busqueda = 4;
    // cout << "resultado busqueda binaria: " << binarySearch(selecction_sort_array, 0, length, numero_busqueda) << endl
    //      << endl;

    // // merge sort

    // int merge_sort_array[n];
    // copy(&array[0], &array[n], &merge_sort_array[0]);
    // mergeSort(merge_sort_array, 0, length - 1);
    // imprimir(merge_sort_array, length);

    // quick sort

    // int quick_sort_array[n];
    // copy(&array[0], &array[n], &quick_sort_array[0]);
    // quickSort(quick_sort_array, 0, length - 1);
    // imprimir(quick_sort_array, length);

    // count sort

    int count_sort_array[n];
    copy(&array[0], &array[n], &count_sort_array[0]);
    auto start = high_resolution_clock::now();
    countSort(count_sort_array, length);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    imprimir(count_sort_array, length);
        cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 1;
}