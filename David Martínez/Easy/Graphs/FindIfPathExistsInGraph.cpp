#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adjList(n);
        vector<bool> seen(n, false);
        int u;
        int v;
        
        for(int i = 0; i < edges.size(); i++){
            u = edges[i][0];
            v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        DFS(source, adjList, seen);
        
        return seen[destination];
    }    
    
    void DFS(int node, vector<vector<int>> & adjList, vector<bool> & seen){
        
        seen[node] = true;
        
        for(int i = 0; i < adjList[node].size(); i++){
            int currVertex = adjList[node][i];
            if(seen[currVertex] == false){
                DFS(currVertex, adjList, seen);
            }
        }
        
    }
};