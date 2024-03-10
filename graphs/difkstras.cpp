#include<iostream>
#include<vector>
#include<map>
using namespace std;
class graph{
    public:
    int vertices;
     vector<vector<int>> a; // Use vector for dynamic memory allocation
     
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
};
void dijikstra(){
    int distance[vertices];
    for(int i=0;i<vertices;i++){
    	distance[i]=INT_MAX;
	}
	
	set<pair<int,int>>st;
	st.insert({0,source});
	dist[source]=0;
	
	while(!st.size()=0){
		auto node=*st.begin();
		
		int v=node.second;
		int dist=node.first;
		
		
	}
	
	

	
	
	
    
    
    
}
int main(){
        graph myGraph(4);

    // Add edges to the graph
    myGraph.addEdge(0, 1, 10);
    myGraph.addEdge(0, 2, 15);
    myGraph.addEdge(1, 2, 20);
    myGraph.addEdge(2, 3, 5);

    // Display the graph
    myGraph.printadjencymatrix();

    return 0;
}