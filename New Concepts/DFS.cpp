#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
public:
    // properties
    unordered_map<int, vector<int>> adj; // adjacencies list
    unordered_set<int> visited;          // visited nodes

    // methods
    void addEdge(int node, int connection);

    void DFSRecursive(int node);
    void DFSIterative(int node);
    void DFSIterativeHelper(int node);
};

void Graph::addEdge(int node, int connection)
{
    adj[node].push_back(connection);
}

void Graph::DFSRecursive(int node)
{

    // set as visited
    visited.insert(node);
    cout << node << endl;

    // traverse adjacencie list of that node
    for (int a : adj[node])
    {
        if (visited.find(a) == visited.end())
        {
            DFSRecursive(a);
        }
    }
}

void Graph::DFSIterative(int node)
{

    // create stack
    stack<int> stack;

    // push current source node to stack
    stack.push(node);

    // while stack is not empty
    while (!stack.empty())
    {

        // get top element
        int top = stack.top();
        stack.pop();

        // set as visited
        visited.insert(top);
        cout << top << endl;

        // traverse its adjacencie list
        for (int a : adj[top])
        {
            if (visited.find(a) == visited.end())
            {
                stack.push(a);
            }
        }
    }
}

void Graph::DFSIterativeHelper(int node)
{
    for (auto a : adj)
    {
        DFSIterative(a.first);
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 4);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";

    // Function call
    g.DFSIterative(2);

    return 0;
}