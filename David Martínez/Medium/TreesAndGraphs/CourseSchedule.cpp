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


};