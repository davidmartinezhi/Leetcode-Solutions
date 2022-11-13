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
  - **DONE:**ramificación y poda
  - manacher
  - busquedas con el suffix array
  - implementación de trie 
  - **DONE:** Dijkstra & Floyd
  - Prim & Kruskal
  - ABB optimo de Gilbert and Moore
  - Algoritmo de coloreo de grafos
  - Algoritmo de flujo máximo en un grafo
  - Tecnicas de busqueda avanzada
    - Algoritmos fundamentales (DFS, BFS, Lateral)
    - Backtracking and bitmask
    - Backtracking con poda pesada
    - Meet in the middle
    - Heuristics and search strategies (A* and IDA*)
    - Algoritmo de mejora iterativa
    - Algoritmos de optimización
      - Busqueda de escalada (hill-climbing)
      - Recocido simulado (simmulated annealing)

# Geometría Computacional

Se recibe normalmente un conjunto de objetos geométricos
- conjunto de puntos
- conjuntos de segmentos de línea
- los vértices de un polígono en orden de las manecillas del reloj

## Campos importantes donde se usa
- Gráficos por computadora
- Róbotica (problemas de velocidad y planeación de movimientos).
- Sistemas de información geográfica (localización y busqueda geometrica, planeación de rutas).
- Diseño de circuitos integrados (diseño geométrico y verificación).
- Ingeniería asistida por computadora (generación de malla).
- Visión computacional (reconstrucción 3D).

## Temas
- Proximidad e intersección
- Diagramas de voronoi y triangulación de Delaunay
- Búsqueda Geométrica
- Arreglos de hiperplanos
- Cascos convexos, politopos y computación
- Algoritmos aleatorizados

## Problemas clásicos
- Intersección de segmentos. ¿Se cruzan dos segmentos?
- Camino simple cerrado. Dado un conjunto de puntos, encontrar un poligono
  donde ninguna de sus aristas se crucen.
- Inclusión en polígono. ¿El punto se encuentra dentro o fuera del polígono?

## Producto cruz entre segmentos
p1 x p2 = x1y2 - x2y1
- Si es positivo, p1 se encuentra orientado en sentido de las manecillas del reloj de p2 con respecto al origen (giro derecha)
- De lo contrario se encuentra contrario a manecillas del reloj (giro izquierda)
- Si el producto cruz da 0, vectores son colíneales, apuntan a la misma dirección o en direcciones opuestas (no hay giros)

## Proximidad e intersección



# Tecnicas de busqueda avanzada

Algoritmos basados en objeticos buscan explorar diferentes posibilidades en un espacio de busqueda para encontrar una posible solución a un problema

El objetivo representa la solución del problema formulado

## Formulación del problema 

- algoritmo de busqueda toma problema de entrada y devuelve solución en forma de secuencia de acciones

Primer paso para resolver problema es la formación del objetivo

    modelo de transición
        cuatro compontentes:
            -Estado inicial del agente
            -Descripción de posibles acciones
             dado estado S, existe conjunto de acciones aplicables para S
            -Prueba objetivo, determina si al relaizar una acción se alcanza el estado objetivo
            -Función de costo para evaluar los posibles caminos o secuencia de acciones con costo   númerico. Cada paso o acción puede tener un costo individual.

# Estrategias de búsqueda no informada
    busquedas que no cuentasn con información adicional cerca de los
    estados más allá de la que proporciona la def del problema

    Principal función es generar los sucesores y distinguir entre
    un estado objetivo de uno que no lo es

    b siendo factor de ramificación

    ## BFS
        tiempo y espacio exponencial O(b^d+1)

    ### costo uniforme
        tiempo y espacio exponencial

    ##DFS
        tiempo b^m
        espaceio b*m
    ### DFS con limites
        b^l
        b*l

    ### Iterative deeping
        

    ##Busqueda bidireccional
        BFS en dos sentidos, desde estado inicial a estado final
        expande y donde los nodos coincidan, ahí se pueden unir los caminos


## Backtracking con bitmask
Definir estado inicial: asignación vacía
Función sucesor: como generamos nuevos nodos y asignamos valores sin violar restricciones
Test objetico: 
Costo del camino: 

O(d^n) n es variables y d el tamaño maximo del dominio

## Bitmask
También conocido como pequeño conjunto ligero de valores booleanos. Entero
es almacenado en memoria como unas ecuencia o cadena de bits. Podemos usar enteros
para representar un pequelo conhunto ligero de valores booleanos.

Todas las operaciones de conjuntos involucran solo la operación a 
nivel 

Algoritmo apriori
Se usa para mindar datos
Elementos o conjuntos de interes y conjuntos no de interes, union entre esos
elementos hace que la unión sea irrelevante.
Algoritmo hace el filtro de info para solo dar conjuntos relevantes.


