#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{

    // No. of vertices
    int V;

    // Pointer to an array containing adjacency lists
    vector<vector<int>> adj;

public:
    // Constructor
    Graph(int V);

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // Prints BFS traversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    // declare visited nodes data structure and queue
    unordered_set<int> visited;
    queue<int> queue;

    // mark first node as visited and push to queue
    visited.insert(s);
    queue.push(s);

    // check nodes in queue, while queue is not empty
    while (!queue.empty())
    {

        // get front node
        int front = queue.front();
        cout << front << endl;
        queue.pop();

        // traverse adjacent nodes
        for (int adjacent : adj[front])
        {

            // check if it has not been visited
            if (visited.find(adjacent) == visited.end())
            {
                visited.insert(adjacent); // add to visited
                queue.push(adjacent);     // push to queue of nodes to visit next
            }
        }
    }
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}