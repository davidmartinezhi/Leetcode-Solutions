#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

//3 soluciones. DFS For deadlock detection with vector, and unordered map
//last solution uses topological sort and is the most optimal

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        info
            input: 
                int numCourses: total of courses you hace to take
                array prerequisites: with arrays of size two inside 
                    [ai, bi] you must take course b as prerequisite for course a
                
            output: true if you can finish all courses, else false
            
            constraints:
                numCourses in range 1 to (including) 2,000
                array length between 0 and 5,000
                ai, bi range from 0 to numCourses
                all pairs are unique
                
        example
        
            numCourses = 2, prerequisites = [[1,0]]
            -> true
            
            {
                0: 1
            }
            
            numCourses = 2, prerequisites = [[1,0],[0,1]]
            -> false
            
            {
                0: 1
                1: 0
            }
            
            numCourses = 4, prerequisites = [[1,0], [2,1], [3,0]]
            ->true
            
            {
                0: [1, 3],
                1: 2
            }
            
        brute force:
            dfs, map adjacency and see if there is a loop in any course
            runtime: O(n)
            extra sapce: O(n)
            
        optimize:
            bcr: O(n)
            is there a way to get constant extra space?
            
            if used adjacency lists
                time: O(v+e)
        
        walkthrough:
            have counter to know how many courses we have
            create dictionary with lists
            have list for checked out numbers
            add each adjacency
            
            for each key in the dictionary check for its key adjacencies
                if any adjacency is a parent, return false
            
            
        test:
            
            
        */
        
        /*
//1.
        //tiene limitantes en time complexity
        //no prerequisites check
        if(prerequisites.size() == 0) return true;
        
        //declare varibles
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> visited(numCourses, 0);
        
        //fill adjacencies info
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        //traverse edges
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0 && !dfs(adj, visited, i)) return false;
        }
        
        return true; 
    }
    
    bool dfs(vector<vector<int>> adj, vector<int> visited, int v){
        if(visited[v] == 1) return false;
        visited[v] = 1;
        
        for(int ad : adj[v]){
            if(!dfs(adj, visited, ad)) return false;
        }
        
        visited[v] = 2;
        return true;
    }
    */

//2.    
    /*
        //no prerequisites check
        if(prerequisites.size() == 0) return true;
        
        //declare varibles
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> visited;
        vector<int> exists;

        //fill adjacencies info
        for(int i = 0; i < prerequisites.size(); i++){
            if(prerequisites[i][0] == prerequisites[i][1]) return false;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            exists.push_back(prerequisites[i][0]);
            
        }
        
        //fill visited info
        for(auto ad : adj){

            visited[ad.first] = 0;
             
        }
        
        //traverse edges of existing courses
        for(int i = 0; i < exists.size(); i++){
            if(visited[exists[i]] == 0 && !dfs(adj, visited, exists[i])) return false;
        }
        
        return true; 
    }
    
    bool dfs(unordered_map<int, vector<int>> & adj, unordered_map<int, int> & visited, int & v){
        
        //if it has been visited, and we come from it
        if(visited[v] == 1) return false;   //return false
        
        //mark as visited
        visited[v] = 1;
        
        //check adj
        for(auto ad : adj[v]){
            if(!dfs(adj, visited, ad)) return false;    //dfs
        }
        
        visited[v] = 2; //mark as completed the visit
        return true;    //return true
    }
    */

//3.
        //no prerequisites check
        if(prerequisites.size() == 0) return true;
        
        //declare varibles
        vector<vector<int>> adj(numCourses, vector<int>()); //adjacencies
        vector<int> indegreeCounts(numCourses, 0);  //how many nodes point to that single node
        queue<int> starts;  //queue for nodes who are not being pointed by other nodes
        int counter = 0;    //nodes found in the traversal
        
        //1. fill adjacencies and indigree
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);   //for each course, add prerequisite
            indegreeCounts[prerequisites[i][1]]++;  //add how many courses point to that prerequisite
        }
        
        //2. get nodes with indegree of 0 to the queue
        for(int i = 0; i < indegreeCounts.size();i++){
            if(indegreeCounts[i] == 0) starts.push(i);  //Add courses with no prerequisites to queue
        }
        
        //3. process the queue
        while(!starts.empty()){
            int node = starts.front();  //get the node
            starts.pop();
            counter++;  //update counter
            
            for(int i = 0; i < adj[node].size(); i++){
                
                indegreeCounts[adj[node][i]]--; //update how many times the corresponding pre appears
                
                if(indegreeCounts[adj[node][i]] == 0){
                    starts.push(adj[node][i]);  //if the course gets to 0, we add it
                }
            }
            
        }
        
        return counter == numCourses;   //return if nodes found is the same as numCourses
    }
};

/*
tiempo: 45+
Complexity:
    time: Overall O(v+e) vertices + edges = courses + prerequisites

            O(v+e) fill adj and indegree
            O(v) get courses with indegree 0
            O(v+e) traverse prerequisites for each course

    extra space: O(v+e)

Notes:
    Me siento orgulloso de que entendí el problema y que era con grafos por la manera en la que estaba
    planteado el problema. Super que era grafos dirigidos y tenía que ver que no hubiera un ciclo

    Pense en DFS y si algo se repite, es un ciclo. Pero resulto no ser muy optimo.

    Topological sort sirve para ordenar prerequisitos y en este caso, saber si no existe un ciclo.
    El algoritmo implementado es Kahn Algorithm
        1.Fill indegree and adj
        2.Add to queue nodes with indegree 0
        3.Start from those nodes to traverse and update indegree
            if indegree gets to 0, add it to the queue

*/