# Algoritmos de Ordenación, Búsqueda y Estructuras de Datos

## 1. Recursividad 🔄

### 1.1 Fundamentos
La recursividad es un concepto fundamental donde una función se llama a sí misma. Se divide en:
- **Recursividad directa**: La función se llama directamente
- **Recursividad indirecta**: Se realiza a través de otra función

### 1.2 Componentes Esenciales
1. 🎯 Caso base (condición de parada)
2. 📞 Llamada recursiva
3. 🔄 Acercamiento al caso base

### 1.3 Ejemplo Práctico
```cpp
// Cálculo del factorial
long factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
```

## 2. Algoritmos Divide y Vencerás 🔨

### 2.1 Principios
- División del problema en subproblemas más pequeños
- Resolución recursiva de subproblemas
- Combinación eficiente de soluciones

### 2.1 Características
- División del problema en subproblemas más pequeños
- Resolución recursiva de subproblemas
- Combinación de soluciones

### 2.2 Ejemplo: Torres de Hanoi
```cpp
void hanoi(char varinicial, char varcentral, char varfinal, int n) {
    if (n == 1) {
        cout << "Mover disco 1 desde " << varinicial << " a " << varfinal;
    } else {
        hanoi(varinicial, varfinal, varcentral, n-1);
        cout << "Mover disco " << n << " desde " << varinicial << " a " << varfinal;
        hanoi(varcentral, varinicial, varfinal, n-1);
    }
}
```

## 3. Algoritmos de Ordenación Básicos

### 3.1 Ordenación por Intercambio
- Compara pares de elementos adyacentes
- Complejidad: O(n²)
```cpp
void ordIntercambio(int a[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (a[i] > a[j])
                intercambiar(a[i], a[j]);
}
```

### 3.2 Ordenación por Selección
- Busca el mínimo y lo coloca en posición
- Complejidad: O(n²)
```cpp
void ordSeleccion(double a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        if (i != min)
            intercambiar(a[i], a[min]);
    }
}
```

### 3.3 Ordenación por Inserción
- Construye la solución insertando elementos en la parte ordenada
- Complejidad: O(n²)
```cpp
void ordInsercion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int aux = a[i];
        int j = i;
        while (j > 0 && aux < a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = aux;
    }
}
```

### 3.4 Ordenación Shell
- Mejora de la inserción directa
- Usa incrementos decrecientes
- Complejidad: O(n^3/2) promedio

### 3.5 Quicksort
- Algoritmo divide y vencerás
- Usa pivote para particionar
- Complejidad: O(n log n) promedio
```cpp
void quicksort(double a[], int primero, int ultimo) {
    int i = primero, j = ultimo;
    double pivote = a[(primero + ultimo) / 2];
    
    do {
        while (a[i] < pivote) i++;
        while (a[j] > pivote) j--;
        
        if (i <= j) {
            intercambiar(a[i], a[j]);
            i++; j--;
        }
    } while (i <= j);
    
    if (primero < j) quicksort(a, primero, j);
    if (i < ultimo) quicksort(a, i, ultimo);
}
```

## 4. Búsqueda en Listas

### 4.1 Búsqueda Secuencial
- Recorre la lista elemento por elemento
- Complejidad: O(n)
```cpp
int busquedaSecuencial(int arr[], int n, int clave) {
    for (int i = 0; i < n; i++)
        if (arr[i] == clave)
            return i;
    return -1;
}
```

### 4.2 Búsqueda Binaria
- Requiere lista ordenada
- Divide el espacio de búsqueda por la mitad
- Complejidad: O(log n)
```cpp
int busquedaBinaria(int a[], int n, int clave) {
    int bajo = 0, alto = n-1;
    while (bajo <= alto) {
        int medio = (bajo + alto)/2;
        if (clave == a[medio]) return medio;
        else if (clave < a[medio]) alto = medio-1;
        else bajo = medio+1;
    }
    return -1;
}
```

## 5. Ordenación con Urnas (Binsort y Radixsort)

### 5.1 Binsort
- Usa urnas para distribuir elementos
- Requiere rango conocido de valores
- Complejidad: O(n) en casos ideales

### 5.2 Radixsort
- Ordena por dígitos
- No usa comparaciones
- Complejidad: O(d*n) donde d es número de dígitos

## 6. Notación O-grande

### 6.1 Complejidades Comunes
- O(1): Constante
- O(log n): Logarítmica
- O(n): Lineal
- O(n log n): Logarítmica lineal
- O(n²): Cuadrática
- O(2^n): Exponencial

### 6.2 Propiedades
1. c*O(f(n)) = O(f(n))
2. O(f(n)) + O(g(n)) = O(max(f(n),g(n)))
3. O(f(n)) * O(g(n)) = O(f(n)*g(n))

## 7. Backtracking (Vuelta Atrás)

### 7.1 Características
- Búsqueda exhaustiva sistemática
- Prueba todas las posibilidades
- Retrocede cuando encuentra camino sin solución

### 7.2 Ejemplos de Aplicación
1. Problema de las N Reinas
2. Laberinto
3. Problema de la mochila
4. Sudoku

### 7.3 Estructura General
```cpp
void backtrack(Estado estado) {
    if (esSolucion(estado)) {
        procesarSolucion(estado);
    } else {
        for (cada candidato) {
            if (esValido(candidato)) {
                aplicarCandiato(estado);
                backtrack(estado);
                deshacerCandidato(estado);
            }
        }
    }
}
```

## 8. Comparación de Eficiencias

| Algoritmo | Mejor Caso | Caso Promedio | Peor Caso | Espacio |
|-----------|------------|---------------|------------|---------|
| Inserción | O(n) | O(n²) | O(n²) | O(1) |
| Selección | O(n²) | O(n²) | O(n²) | O(1) |
| Quicksort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Mergesort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Búsqueda Binaria | O(1) | O(log n) | O(log n) | O(1) |
| Búsqueda Secuencial | O(1) | O(n) | O(n) | O(1) |

## 9. Recomendaciones Prácticas

1. Para listas pequeñas (<50 elementos):
   - Usar inserción o selección
   
2. Para listas medianas:
   - Usar Shellsort
   
3. Para listas grandes:
   - Usar Quicksort o Mergesort
   
4. Para búsqueda:
   - Lista desordenada: búsqueda secuencial
   - Lista ordenada: búsqueda binaria

5. Para problemas de optimización:
   - Considerar algoritmos de backtracking
   - Evaluar si se necesita solución óptima o aproximada

## 9. Guía Práctica de Selección de Algoritmos 📊

### 9.1 Por Tamaño de Datos
| Tamaño | Recomendación |
|--------|---------------|
| < 50 elementos | Inserción/Selección |
| 50-500 elementos | Shellsort |
| > 500 elementos | Quicksort/Mergesort |

### 9.2 Por Tipo de Búsqueda
- **Lista desordenada**: Búsqueda secuencial
- **Lista ordenada**: Búsqueda binaria
- **Grandes volúmenes**: Estructuras de datos especializadas (hash tables)

### 9.3 Consideraciones de Optimización
- Evaluar requisitos de memoria
- Considerar estabilidad del algoritmo
- Analizar características de los datos

> **Nota**: La elección del algoritmo debe basarse en el contexto específico del problema y los recursos disponibles.
