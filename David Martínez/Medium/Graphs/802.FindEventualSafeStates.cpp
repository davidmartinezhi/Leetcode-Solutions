#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        /*
        info
            input: directed graph of n nodes, graph represented by 2d int array, graph[i] are adjacent vertices to node i
                    node is terminal if there are not outgoing edges. node is safe if every path leads to terminal node or another safe node
            output: array containing all safe nodes of the graph
            constraints:
                n == graph.size
                size in range 1 and 10,000
                graph[i] is sorted in increasing order
                graph may contain self loops
                number of edges between 1 and 40,000

        example
            [[1,2],[2,3],[5],[0],[5],[],[]]
            -> [2,4,5,6]

        brute force
            DFS
            check each adjacent node path, if an adjacent node is not safe or terminal ignore, else add to answer

            complexity:
                time: O(v+e)
                extra space: O(v+e)

        optimize
            bcr: O(v+e)

        test:
            not all paths lead to terminal node
            all paths lead to terminal node

            node connects to terminal node
            node is connected to safe node

        */

        // visited and safe nodes
        int n = graph.size();
        unordered_map<int, bool> safe;
        vector<int> safeNodes;

        for (int i = 0; i < n; i++)
        {
            if (DFS(graph, safe, i))
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }

    bool DFS(vector<vector<int>> &graph, unordered_map<int, bool> &safe, int node)
    {

        // check if value is already in safe
        if (safe.find(node) != safe.end())
            return safe[node];

        // assume value is false
        safe[node] = false;

        // traverse adjacencies
        for (int adj : graph[node])
        {

            if (!DFS(graph, safe, adj))
                return false;
        }

        safe[node] = true;
        return true;
    }
};