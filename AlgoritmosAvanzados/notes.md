# Notas

# Backtracking
Algoritmo que busca o genera sequencia de componentes donde va intendando resolver cada componente de tal forma que encuentra una solución o regresa al componente anterior y repite.

### Complejidad
    Complejidad exponencial: Altura^n (profundidad por numero de nodos) 

### Problema de satisfacción de restricciones
Asignación completa.

## Branch and  bound (ramidicación y poda)
Uilizando priority queues, o el algoritmo hungaro de khan

# STRINGS
    - KMP (knuth morris pratt)
    - Rabin-Karp
    - Automata finito

## KMP (knuth morris pratt)
    Busqueda de substrings en O(m+n) tiempo.
    m por el preprocesado y k por la busqueda.

    Usa función y tabla auxiliar para guardar info
    compute-prefix-function

- parte 1: Construimos tabla prefijo-sufijo

- parte 2: Llenamos la tabla
  - SI NO SON IGUALES: pi[q]=0 u q = q+1
  - SI SON IGUALES: pi[q] = k+1, q = q+1
    SI NO SON IGUALES CUANDO: q lelga al final del string, se asigna pi[q] a pi[1]



=== Knapsack using tabulation (bottom-up)


    Why tabulation?
    Recursion uses stack memory and takes more time
    It's better to use heap memory rather than stack memory, there is more heap memory available generally

    How To Build Table?
        Identify on what states does your solution really depends


==Okay ya lo entendí

Memoization es top-down o bottom-up con recursividad y referencia a data structure que guarda datos
Tabulation es con iteratividad
    top-down es iterativo
    bottom-up también es iterativo


==Identifying knapsack problems
https://www.youtube.com/watch?v=oaloiuvGcQg&list=PLEJXowNB4kPxBwaXtRO1qFLpCzF75DYrS&index=7

    Knapsack problems patterns
        1) An array (with k number of properties)
        2) Max value W (knapsack capacity)
        We have choice to include or exclude items
        Number of times we can choose item defines the type of knapsack
        (conatrints definte knapsack type)

    Bounded:
        we can take items 0 to n times

    0-1:
        special case bounded knapsack, only take 0 or 1

    Unbounded:
        Can take infinite number of each item

================================================
Classifications base on goals:
    Subset sum problem T/F find if subset that adds up to given sum exists
    Equal subset problem    S1-S2 = 0
    Minimum Subset sum problem  S1-S2 = MIN
    count subsets problem S1 = value

# Algoritmo Djikstra

# Algoritmo de Floyd

# Algoritmo del viajero

# Algoritmo de prim
## Encontrar árbol de mínima extensión

# Algoritmo de kruskal
## Encontrar árbol de mínima extensión

  1. Cada vertice es un conjunto separado
  2. Conjuntos separados se agregan al conjunto respuesta


# ABB óptimo de Gilbert and Moore



# Problema del flujo máximo

## methods
    - ford-fulkerson


### ford-fulkerson


## Graph coloring/chromatic number color



checkar
  - ramificación y poda
  - manacher
  - busquedas con el suffix array
  - implementación de trie 
  - **DONE:** Dijkstra & Floyd
  - Prim & Kruskal
  - ABB optimo de Gilbert and Moore
  - Algoritmo de coloreo de grafos
  - Algoritmo de flujo máximo en un grafo



