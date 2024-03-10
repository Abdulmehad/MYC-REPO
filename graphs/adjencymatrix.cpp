#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
class graph{
    public:
    int vertices;
     vector<vector<int>> a;
     // map<int, map<int, int>> a; // Use map for dynamic memory allocation
     
    graph(int n): a(n, vector<int>(n, 0)){
    vertices=n;
    }

void addEdge(int u,int v,int cost){
    a[u][v]=cost;
    a[v][u]=cost;
}
void printadjencymatrix(){
    for(int i=0;i<vertices;i++){
        cout << "[";
        for(int j=0;j<vertices;j++){
            cout << a[i][j];
            if(j != vertices-1) {
                cout << ", ";
            }
        }
        cout << "]";
        if(i != vertices-1) {
            cout << ", ";
        }
    }
    
}
void bfs(int start) {
    // Making a queue
    queue<int> q;
    int n = a.size();
    // Making a visited array
    bool* visited = new bool[n] {false};

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for (int neighbour = 0; neighbour < vertices; ++neighbour) {
            if (a[curr][neighbour] != 0 && !visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

    delete[] visited;
}


};

int main(){
        graph myGraph(4);

    // Add edges to the graph
    myGraph.addEdge(0, 1, 10);
    myGraph.addEdge(0, 2, 15);
    myGraph.addEdge(1, 2, 20);
    myGraph.addEdge(2, 3, 5);

    // Display the graph
    myGraph.printadjencymatrix();
    cout<<endl;
    myGraph.bfs(2);

    return 0;
}