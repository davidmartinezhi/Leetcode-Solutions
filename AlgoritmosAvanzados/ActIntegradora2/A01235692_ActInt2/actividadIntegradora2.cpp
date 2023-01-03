/*
Actividad Integradora 2
Help a company that wants to venture into Internet services by:


Created: Nov 22, 2022 11:34am    Last Modification: Nov 29, 2022 01:15pm

David Gerardo Martínez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruán - A01197898

*/

#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef  pair<int, int> iPair;


struct Graph{
    int Vertices, e;

    vector<pair<int, iPair> > Edges;

    Graph(int Vertices, int e){

        this->Vertices = Vertices;

        this->e = e;
    }

    void addEdge(int u, int v, int w){
        Edges.push_back(make_pair(w, make_pair(u, v)));
    }

    int kruskalMST();
};

struct disjointSets{
    int *parent, *rnk;

    int n;

    disjointSets(int n){
        this->n = n;
        parent = new int[n+1];

        rnk = new int[n+1];

        for (int i = 0; i <= n; i++){

            rnk[i] = 0;
            parent[i] = i;

        }
    }

    int find(int u){
        if (u != parent[u])

            parent[u] = find(parent[u]);

        return parent[u];
    }

    void merge(int x, int y){

        x = find(x), y = find(y);

        if (rnk[x] > rnk[y])
            parent[y] = x;

        else
            parent[x] = y;

        if (rnk[x] == rnk[y])

            rnk[y]++;
    }
};

// Obtains the list of arcs
// Complexity :
//      O(ElogE +ElogV)
//      where Vertices is the number of vertices and e is the
//      number of edges that exist in the Colonial graph

int Graph::kruskalMST()
{
    int mstWt = 0;

    sort(Edges.begin(), Edges.end());
    disjointSets ds(Vertices);

    vector< pair<int, iPair> >::iterator it;
    for (it=Edges.begin(); it!=Edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v){

            cout <<"("<<char(u+65) << "," << char(v+65) << ")  ";

            mstWt += it->first;

            ds.merge(set_u, set_v);
        }
    }

    return mstWt;
}

bool bfs(vector<vector<int> > rmatrix, int s, int t, int parent[], int Vertices);

void fordFulkerson(vector<vector<int> > matrix, int s, int t, int Vertices);

void printMatrix(vector<vector<int> > &matrix, int points);

vector<vector<int> > matrixAdjacent(vector<int> &xCoordinate, vector<int> &yCoordinate, int points);

int minDistance(vector<int> &distance, vector<bool> &visited, int &cost);

void minRoute(vector<vector<int> > &matrix, int node, vector<bool> &visited, int &cost);

int main() {

   int points, x, y;

   cin>>points;

   vector<int> xCoordinate, yCoordinate;
   vector<pair<int,int> > central, connection, Colonial;

   for (int i=0; i<points; i++){
       cin>>x>>y;

       xCoordinate.push_back(x);
       yCoordinate.push_back(y);

       Colonial.push_back(make_pair(x,y));
   }
   vector<vector<int> > matrix, fmatrix;


   matrix=matrixAdjacent(xCoordinate,yCoordinate,points);

   //printMatrix(matrix,points);

   int Edges=(points*(points+1)/2)-points;

    Graph g(points,Edges);

    for(int i=0; i<points; i++){

        for(int j=i+1; j<points; j++){

            g.addEdge(i, j, matrix[j][i]);

        }
    }
    cout << endl;
    cout << "Optimal connection between colonies:"<<endl;
    int mstWt = g.kruskalMST();
    cout << endl<<endl;

    cout << "Distance: " << mstWt<<endl<<endl;
    //cout << mstWt <<endl;

    cout << "Rout "<<endl;

    int node = 0, cost = 0;

    vector<bool> visited(matrix[0].size(), false);
    cout<<"Path: ";

    minRoute(matrix, node, visited, cost);

    int a;

    for(int i = 0; i < points; i++){

        vector<int> aux;
		for(int j = 0; j < points; j++){

			cin >> a;
			if(a==-1){
                a=0;
			}
			aux.push_back(a);
		}
        fmatrix.push_back(aux);
	}

    cout<<"Flow: "<<endl;
	for(int i = 0; i < points; i++){

        for(int j = 0; j < points; j++){

            if(i==j){
                continue;
            }
            else{
            fordFulkerson(fmatrix, i, j, points);
            }
        }
	}

	int centralSize, connectionSize;

	cin>>centralSize;

	for (int i=0; i<centralSize; i++){

       cin>>x>>y;
       central.push_back(make_pair(x,y));

    }

    cin>>connectionSize;
	for (int i=0; i<connectionSize; i++){
       cin>>x>>y;
       connection.push_back(make_pair(x,y));
    }
}
// Creation of an adjacency matrix
// Input: Int vectors with for the x and y coordinates, integer number
// Complexity :
//  O(Vertices^2)
// where Vertices is the number of vertices that exist in the Colonial graph
vector<vector<int> > matrixAdjacent(vector<int> &xCoordinate, vector<int> &yCoordinate, int points){
    int aux_v;
    vector<int> aux;
    vector<vector<int> > matrix;
    for(int i=0; i<points;i++){
       for(int j=0; j<points; j++){

           aux_v=sqrt(((xCoordinate[i]-xCoordinate[j])*(xCoordinate[i]-xCoordinate[j])) +

           ((yCoordinate[i]-yCoordinate[j])*(yCoordinate[i]-yCoordinate[j])));
           aux.push_back(aux_v);

       }
       matrix.push_back(aux);
       aux.clear();
   }
   return matrix;
}

void printMatrix(vector<vector<int> > &matrix, int points){

    cout<<"Matriz de adyacencias: "<<endl;
    for(int i=0; i<points;i++){

       for(int j=0; j<points; j++){
           cout<<matrix[i][j]<<" ";
       }

       cout<<endl;
   }
   cout<<endl;
}

bool bfs(vector<vector<int> > rmatrix, int s, int t, int parent[], int Vertices){

    bool visited[Vertices];

    memset(visited, 0, sizeof(visited));

    queue<int> q;

    q.push(s);

    visited[s] = true;

    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();

        q.pop();

        for (int v = 0; v < Vertices; v++) {

            if (visited[v] == false && rmatrix[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;

                    return true;
                }
                q.push(v);

                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}
//Get the maximum flow values
//Input: Vector of integer, integer number, integer number, integer number
//Complexity :
//    ​​O(VE^2)
//     where Vertices is the number of vertices and e is the
//      number of edges that exist in the Colonial graph

void fordFulkerson(vector<vector<int> > matrix, int s, int t, int Vertices){

    int u, v;

    vector<vector<int> > rmatrix = matrix;

    int parent[Vertices];

    int max_flow = 0;

    while(bfs(rmatrix, s, t, parent, Vertices)){

        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rmatrix[u][v]);

        }

        for(v = t; v != s; v = parent[v]){

            u = parent[v];
            rmatrix[u][v] -= path_flow;

            rmatrix[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    cout << "Suburb " << s+1 << " ->  Suburb " << t+1 << " Flow = " << max_flow << endl;
}

int minDistance(vector<int> &distance, vector<bool> &visited, int &cost){
    int index=-1;
    double min = INT_MAX;
    for(int i = 0; i< distance.size(); i++){

        if(min > distance[i] && !visited[i]){

            min = distance[i];
            index = i;
        }
    }

    if (index==-1){
        cost+=distance[0];
        return -1;
    }

    cost += min;

    return index;
}
//Gets the shortest route
//Input: Vector of integer, node, vector, integer 
//Complexity :
//     O(n^2)
//     Minimum distance: O(n) where n is the number of columns in the matrix
//     Minimal path: O(n) where n is the number of rows in the array
void minRoute(vector<vector<int> > &matrix, int node, vector<bool> &visited, int &cost){

    int index;
    if (!visited[node] && node<visited.size()) {

        visited[node] = true;

        cout<<char(node+65)<<"->";
        index=minDistance(matrix[node], visited, cost);
        if (index != -1){
            minRoute(matrix, index, visited, cost);
        }else{
            cout<<"A ";
            cout<<"Cost = "<< cost<<endl<<endl;
        }
    }
}


void travllingSalesmanProblem(vector<vector<int> > matrix, int s, int Vertices){
    vector<int> vertex;
    vector<int> path, aux_path;
    for (int i = 0; i < Vertices; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;
    do {

        int current_pathweight = 0;

        int k = s;

        aux_path.push_back(s);

        for (int i = 0; i < vertex.size(); i++) {

            current_pathweight += matrix[k][vertex[i]];
            k = vertex[i];
            aux_path.push_back(k);

        }

        aux_path.push_back(s);
        current_pathweight += matrix[k][s];

        if(min_path>current_pathweight){
            path=aux_path;
        }
        aux_path.clear();
        min_path = min(min_path, current_pathweight);


    }while(next_permutation(vertex.begin(), vertex.end()));

    cout << "Minimum cost: " << min_path <<endl;
    cout << "Path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << char(path[i]+65) << " -> ";
    }
    cout << endl;
}