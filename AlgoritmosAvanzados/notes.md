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

## Arreglo z
    









