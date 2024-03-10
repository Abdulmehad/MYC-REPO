#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

class graph {
public:
    int vertices;
    vector<vector<int>> a;

    graph(int n) : a(n, vector<int>(n, 0)) {
        vertices = n;
    }

    void addEdge(int u, int v, int cost) {
        a[u][v] = cost;
        a[v][u] = cost;
    }

    void printAdjacencyMatrix() {
        for (int i = 0; i < vertices; i++) {
            cout << "[";
            for (int j = 0; j < vertices; j++) {
                cout << a[i][j];
                if (j != vertices - 1) {
                    cout << ", ";
                }
            }
            cout << "]";
            if (i != vertices - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
};

void dijkstra(graph &g, int start) {
    const int MAX = INT_MAX;  

    vector<int> arr(g.vertices, MAX);
    vector<bool> visited(g.vertices, false);

    arr[start] = 0;

    for (int k = 0; k < g.vertices - 1; k++) {
        int small = MAX, index;

        for (int i = 0; i < g.vertices; i++) {
            if (visited[i]) {
                continue;
            }

            if (small > arr[i]) {
                index = i;
                small = arr[i];
            }
        }

        visited[index] = true;

        for (int i = 0; i < g.vertices; i++) {
            if (g.a[index][i] == 0 || visited[i]) {
                continue;
            }

            int dis = g.a[index][i];
            dis += arr[index];

            if (dis < arr[i]) {
                arr[i] = dis;
            }
        }
    }

    for (int i = 0; i < g.vertices; i++) {
        if (i == start) {
            continue;
        }
        cout << i << " cost " << arr[i] << endl;
    }
}

int main() {
    graph myGraph(4);

    // Add edges to the graph
    myGraph.addEdge(0, 1, 10);
    myGraph.addEdge(0, 2, 15);
    myGraph.addEdge(1, 2, 20);
    myGraph.addEdge(2, 3, 5);

    // Display the graph
    myGraph.printAdjacencyMatrix();

    // Run Dijkstra algorithm
    dijkstra(myGraph, 0);

    return 0;
}
