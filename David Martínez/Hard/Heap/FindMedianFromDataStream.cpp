#include <iostream>
#include <priority_queue>

using namespace std;

class MedianFinder {
    // Max heap para la mitad izquierda de los números
    priority_queue<int> maxHeap;
    
    // Min heap para la mitad derecha de los números
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // Constructor
    MedianFinder() {
    }
    
    // Función para añadir un número
    void addNum(int num) {
        // Añadir el número al max heap (mitad izquierda)
        maxHeap.push(num);
        
        // Mover el elemento más grande del max heap al min heap (mitad derecha)
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Equilibrar los heaps para que maxHeap tenga más elementos si el total es impar
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    // Función para encontrar la mediana
    double findMedian() {
        // Si los tamaños de los heaps son iguales, la mediana es el promedio de los elementos más grandes de cada heap
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        
        // Si maxHeap tiene más elementos, la mediana es el elemento más grande en maxHeap
        return maxHeap.top();
    }
};

/*
time: 45+ minutes

complexity:
    runtime: O(log n) insertion, O(1) find median
    extra space: O(n) data stream numbers

Saque solución pero no era la más eficiente. 
tenía complejidad de O(n) find median

Se me ocurrío el utilizar 2 heaps pero no me detuve a pensar sobre como iban a interactuar entre sí
esos dos heaps. Talvez así se me hubiera ocurrido la solución rapidamente.

Tengo buena intuición para la solución, pero me desespere y deje de analizar como se iba a mover la info
solo pense en lo que tenía y como llegar ahí aunque hubiera errores. Debo de desacelerarme y 
checar como se comporta el sistema. Buena solución aunque no fuese la más optima tho.
*/