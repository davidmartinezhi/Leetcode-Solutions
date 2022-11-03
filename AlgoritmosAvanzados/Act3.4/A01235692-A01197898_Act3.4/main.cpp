/*
Act3.4
Graph coloring implementation
Based on the Welsh-Powell algorithm, write a C++ program that proposes a solution 
to the graph coloring problem.

INPUT: 
The input to the program is an undirected graph, in the form of an adjacency matrix.

OUTPUT:    
The output is a list of colors assigned to each node.

David Gerardo Martinez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruan - A01197898

Created: Oct 25, 2022 1:08pm    Last Modification: Nov 3, 2022 2:49pm 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//Node class
class Node{
    
    public:
        //variables
        int value; //node value
        int color; //color
        vector<Node*> adj; //adjacent nodes

        //constructores
        Node(): value(0), color(0), adj(vector<Node*>()) {};
        Node(int val): value(val), color(0), adj(vector<Node*>()) {};

        //overload operators
        /*
        bool operator > (const Node & node){ return adj.size() > node.adj.size();};
        bool operator < (const Node & node){ return adj.size() < node.adj.size();};
        bool operator >= (const Node & node){ return adj.size() >= node.adj.size();};
        bool operator <= (const Node & node){ return adj.size() <= node.adj.size();};
        bool operator == (const Node & node){ return adj.size() == node.adj.size();};
        */
};

// class to compare nodes in max heap
class myComparator
{
public:
    int operator() (Node * & node1, Node * & node2)
    {
        return node1->adj.size() < node2->adj.size();
    }
};


//Graph Coloring
/*
Validate that node can be colored
input: node object and current color
complexity
    time: O(n-1)
    extra space: O(1)
*/
bool isValidToColor(Node* & node, int & color) {

    //traverse adjacencies
    for(int i = 0; i < node->adj.size(); i++){
        Node * temp = node->adj[i];

        //if it already has a color and its the same color, return false
        if(temp->color != 0 && color == temp->color) return false;
    }

    return true;
}

/*
Assign a different color to each vertex, the color is different from 
the color in the adjacencies
input: vector of vertices nodes
output: none, the values are assigned with pointers
complexity:
    time: O(n^2)
    extra space: O(n)
*/
void graphColoring(vector<Node*> & vertices){

    //initial color
    int color = 1;

    //vertices not visited and colored, O(n) extra space
    vector<Node*> toVisit = vertices;


    while(!toVisit.empty()){

        //save vertices not visited
        vector<Node*> toVisitTemp;

        //traverse vertices not visited, O(n) time
        for(int i = 0; i < toVisit.size(); i++){

            //get node to color
            Node* toColor = toVisit[i];

            //check if it's a valid to color, O(n) time
            if(isValidToColor(toColor, color)){
                toColor->color = color; //assign color
            }
            else{
                toVisitTemp.push_back(toColor); //add to vertices to visit
            }
        }

        color++; //set new color
        toVisit = toVisitTemp; //update nodes to visit
    }
}

/*
Prints node values
input: Vector with vertices nodes
ouput: none

complexity
    time: O(n)
    extra space: O(1)
*/
void printGraph(vector<Node*> vertices){
    for(int i = 0; i < vertices.size(); i++){
        Node * node = vertices[i];
        cout << "Node: " << node->value << ", Color: " << node->color << endl;
    }
}


/*
Assign a different color to each vertex, the color is different from 
the color in the adjacencies and print the color of each vertex

input: adjacencie matric
output: none

complexity
    time: O(n^2)
    extra space: O(n)
*/
int main()
{

    //Get Input
    int n;
    cin >> n;

    //Declare variables
    //arrange nodes by degrees
    priority_queue<Node*, vector<Node*>, myComparator> maxHeap; //max heap of degrees
    vector<Node*> verticesByDegree; //vertices in ascending degree order
    vector<Node*> vertices(n); //vertices in value order

    int aux;

    //create vertices. O(n)
    for(int i = 0; i < n; i++){
        //Create Node with it's value
        vertices[i] = new Node(i+1);
    }


    //create adjacencies. O(n^2)
    for(int i = 0; i < n; i++){
        
        //get node
        Node* node = vertices[i];

        //get adjacencies
        for(int j = 0; j < n; j++){
            cin >> aux; 

            //insert adjacencie if it exists
            if(aux == 1){
                node->adj.push_back(vertices[j]);
            }
        }

        //add node. O(log(n))
        maxHeap.push(node); //add node to maxHeap
    }
    

    //Get nodes ordered by degree. O(n)
    while(!maxHeap.empty()){
        verticesByDegree.push_back(maxHeap.top());
        maxHeap.pop();
    }

    //graph coloring
    graphColoring(verticesByDegree);

    //print graph
    printGraph(vertices);

    return 0;
}
