#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



class Solution {
public:
    Node* cloneGraph(Node* node) {
        /*
            input: adj List vector
            output: cloned graph
            constraints:
                number of nodes between 0 and 100
                node vals between 1 and 100
                node val is unique for each node
                no repeated edges or self loops
                graph is connected and all nodes can be visited
                
            example
            
            brute force/optimal
                bfs or dfs
                since it's a adj list, we can
                traverse dfs or bfs and colpexity will be
                time: O(v+e)
            
                but I'll need to chek if a value exists
                if it doesn't, I'll create it and start connecting
                
                create vector to store nodes found
                
            walkthrough
                
                delcare variables
                set for visited
                set for nodes in new graph
                queue for nodes to visit next
                
                create first node
                
                while queue is not empty
                traverse first node in queue
                    mark as visited
                    if value doesn't exist:
                        create it
                        add to queue
                    
                    add to adj list
                
            test
                no nodes in graph
                one node in graph
                   
        */
        
        //check of node is nullptr
        if(!node) return node;
        
        //declare variables
        unordered_map<int, Node*> nodesInClone;
        queue<Node*> toVisit;
        
        //add first node, to queue and clone to nodesInClone
        nodesInClone[1] = new Node(1);
        toVisit.push(node);
        
        //traverse
        while(!toVisit.empty()){
            
            //get node from queue
            Node * auxNode = toVisit.front();
            toVisit.pop();
            
            //get node of clone
            Node * cloneNode = nodesInClone[auxNode->val];
            

            //traverse adjacencies of original
            for(int i = 0; i < auxNode->neighbors.size(); i++){
                
                //get neighbor
                Node * neighbor = auxNode->neighbors[i];
                
                //check if value doesn't exists in clone
                if(nodesInClone[neighbor->val] == nullptr){
                    
                    //create it
                    Node * newNode = new Node(neighbor->val);
                    
                    //add to nodesInClone
                    nodesInClone[neighbor->val] = newNode;
                    
                    //add to queue
                    toVisit.push(neighbor);
                }
                
                //add to adjacency of clone
                cloneNode->neighbors.push_back(nodesInClone[neighbor->val]);
            }

        }
        
        //return clone of first node
        return nodesInClone[1];
    }
};

/*
Time:
    45minutes+

Complexity:
    time: O(vertex+edges)
    extra space: O(vertex)

Me gusto que salio el problema a la primera, llevaba tiempo sin trabajar con grafos
pero salio de manera adecuada una solución optima.

Pienso que al familiarizarme con grafos, mi velocidad de resolución de este tipo de problemas
ira incrementando.
*/