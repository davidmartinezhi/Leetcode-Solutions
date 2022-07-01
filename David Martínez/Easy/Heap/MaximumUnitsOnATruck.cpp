#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        /*
            info
                input: matrix where boType[i] = [numberOfBoxes, numberOfUnitsPerBox]
                    numberOfBoxes = number of boxes of type i
                    numberOfUnitsPerBox in each box i
                    
                        int truckSize, max number of boxes that can be put on the truck.
                    
                    Can choose boxes I put on the truck, as long as it does not exceed truckSize
                    
                output: max number of units that can be put in the truck
                
                constraints:
                    array size ranges from 1 to 1,000
                    numOfBoxees and Boxes per unit, numbers ranges from 1 to 1,000
                    truck size ranges from 1 to 1,000,000
            
            example
               [[1,3],[2,2],[3,1]] truckSize = 4
               -> 8
               
               get boxes that store more units first
               [
                3: 1,
                2: 2,
                1: 2
               ]
               
               4 boxes capacity
               -> 3
               (1*3) + (2*2)  = 3 + 4 = 7 + 1 = 8
               
               [[5,10],[2,5],[4,7],[3,9]] truckSize = 10
               -> 91
               
               [
               5: 10,
               3: 9,
               4: 7,
               5: 2
               ]
               
               5 * 10 = 50
               3 * 9 = 27
               2 * 7 = 14
               50 + 27 = 77 + 14 = 91
               
            brute force
               max heap / priority queue to always know box available for max units
               and keep taking boxes from there
               
               [
               [10, 5]
               [9, 3]
               
               ]
               time: O(boxes) = O(n)
               extra space: O(boxes) = O(n)
            
            optimize
                best case runnigtime O(n)
                can I improve memory?
                
                alternative
                Traverse the boxes array to find max each time we run out of boxes
                with certain units
                
                time: O(n^2)
                extra space: O(1)
                
                Ill use brute force
                
            test:
                
                boxes cross truckSize
                boxes don't cross boxSize
                array bigger than trucksize
                trucksize bigger than array
                
                hotspots:
               
        */
        
        //declare variables for maxUnits and priority queue
        int maxUnits = 0;
        priority_queue<pair<int, int>> units;
        int totalBoxes = 0;
        
        //fill priority queue
        for(int i = 0; i < boxTypes.size(); i++){
            //This will create priority queue of max units per box
            units.push(make_pair(boxTypes[i][1], boxTypes[i][0]));
            totalBoxes = totalBoxes + boxTypes[i][0];
        }

        //process boxes with max units until we can't fit more boxes os run out of boxes
        while(totalBoxes > 0 && truckSize > 0){
            
            //get the current amount of boxes and units
            int unitsToAdd = units.top().first;
            int boxes = units.top().second;            
            units.pop();
            
            //add units
            if(truckSize <= boxes){
                maxUnits = maxUnits + (truckSize * unitsToAdd);
                
            }else if(truckSize > boxes){
                maxUnits = maxUnits + (boxes * unitsToAdd);
            }  
            
            truckSize = truckSize - boxes;
            totalBoxes = totalBoxes - boxes;
        }
        
        //return
        return maxUnits;
        
    }
};

/*
time: 35 minutes to finish coding, + 20 minutes on discovering I need totalBoxes variable
Complecity:
    time: O(n)
    extra space: O(n)

Batalle en descubrir que necesitaba totalBoxes porque lo compare con el problema
de applegame y lo quise hacer directamente igual.

No considere el tener la capacidad de cajas y el total de cajas
    Aparte literal lo escribí arriba del loop pero no le hice caso después
    Si nos quedamos sin cajas o se llena el camion, dejamos de meter cajas.

Aún así desde el principio supe como se resolvería e hice una buena implementación


*/