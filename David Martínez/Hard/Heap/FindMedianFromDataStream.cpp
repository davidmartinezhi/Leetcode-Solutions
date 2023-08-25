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
