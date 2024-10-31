# Complejidad Algorítmica y Notación Big O

## Recursos y Complejidades

### Complejidad Espacial

Se refiere a la cantidad de memoria que necesita un algoritmo para funcionar.

- **Ejemplo 1:** Un algoritmo que necesita dos listas auxiliares para ordenar una lista de n elementos, tiene una complejidad espacial de 2n, ya que necesita el doble de memoria que la entrada.
- **Ejemplo 2:** Un algoritmo que intercambia elementos en una lista sin usar listas auxiliares tiene una complejidad espacial constante de 1, ya que solo usa memoria para almacenar un elemento a la vez.

### Complejidad Temporal

Se refiere a la cantidad de tiempo que necesita un algoritmo para ejecutarse.

- **Ejemplo 1:** Un algoritmo que recorre una lista y suma 1 a cada elemento tiene una complejidad temporal lineal de O(n), ya que el tiempo de ejecución aumenta proporcionalmente al tamaño de la lista.
- **Ejemplo 2:** Un algoritmo que compara elementos de dos listas del mismo tamaño para encontrar repetidos tiene una complejidad temporal cuadrática de O(n^2), ya que el número de operaciones aumenta exponencialmente con el tamaño de las listas.

## La Notación Big O

- Big O es una notación matemática que se usa para describir el comportamiento asintótico de una función, es decir, cómo se comporta la función cuando el tamaño de la entrada se acerca al infinito.
- En el contexto de la complejidad algorítmica, Big O representa la cota superior asintótica, es decir, una estimación del máximo tiempo o espacio que necesita un algoritmo para un tamaño de entrada dado.
- Big O se usa para clasificar algoritmos en diferentes órdenes de complejidad, como constante (O(1)), logarítmico (O(log n)), lineal (O(n)), cuadrático (O(n^2)), cúbico (O(n^3)), etc.

## Importancia de la Complejidad

- La complejidad algorítmica es crucial para entender el rendimiento de un algoritmo, especialmente cuando se trabaja con grandes conjuntos de datos.
- Un algoritmo con un orden de complejidad bajo (por ejemplo, constante o lineal) es mucho más eficiente que un algoritmo con un orden de complejidad alto (por ejemplo, cuadrático o exponencial).