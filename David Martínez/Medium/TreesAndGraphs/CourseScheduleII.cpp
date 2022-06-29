#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            1. info
                input: int numCourses that represents total number of courses
                    and array prerequisites containing pairs representing courses
                    pair[0] has as prerequisite pair[1]
                
                ouput: vector with ordering of courses you should take to finish all courses
                        if there are many valid answers, return any of them
                        
                        if courses cannot be completed, return empty string
                        
                constraints:
                    numCourses between 1 and 2,000
                    prerequisites between 0 and numCourses-1
                    all the pairs are distinct
                        
            2. example
                numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
                -> [0,2,1,3]
                
                numCourses = 2, prerequisites = [[1,0]]
                -> [0,1]
                
                numCourses = 1, prerequisites = []
                -> [0]
                
            3. brute force
                kahn's algorithm for topological sort
                complexity:
                    time: O(courses + prerequisites)
                    extra space: O(courses + prerequisites)
            
            4. optimize
                kahn's algorithm is optimal for this problem
            
            5. walkthrough
                fill adj and indegrees
                add to queue nodes with indegree 0
                process queue
            
            7. test
                empty prerequisites. correct
                not possible to finish courses. correct
                possible to finish courses. correct
        */
        
        //no prerequisites
        if(prerequisites.size() == 0){
            vector<int> ans;
            while(numCourses > 0){
                ans.push_back(numCourses-1);
                numCourses--;
            }
            return ans;
        }
        
        //declare variables
        vector<int> ans;
        
        vector<vector<int>> adj(numCourses);    //adjacencies
        vector<int> indegree(numCourses, 0);    //indegree conections
        queue<int> indegreeZero;
        int counter = 0;    //courses in the traversal
        
        //fill adj and indegree
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        //look for nodes with indegree 0 and add them to queue
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) indegreeZero.push(i);
        }
        
        //process queue
        while(!indegreeZero.empty()){
            int node = indegreeZero.front();    //get node
            indegreeZero.pop();
            ans.push_back(node);    //add it to answer vector
            counter++;  //update counter
            
            for(int i = 0; i < adj[node].size(); i++){  //for each adjacency in that node
                indegree[adj[node][i]]--;   //update indegree value of adjacencie
                if(indegree[adj[node][i]] == 0) indegreeZero.push(adj[node][i]); //if adj is 0 add to queue
            }
        }
        
        //check if it's possible to take courses
        if(numCourses != counter) return {};
        
        return ans;
    }
};
