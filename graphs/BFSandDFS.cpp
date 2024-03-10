#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<stack>
using namespace std;
template<class T>
class graph{
    public:
    map<T,list<pair<T,int>>> adj;
    
    void addedge(T u,T v,int weight){
        //cretae an edge u to v
        adj[u].push_back({v,weight}); 
        adj[v].push_back({u,weight});
    }

void print_adjlist() {
    for (auto i : adj) {
        cout << i.first << "->";
        for (auto j : i.second) {
            cout << "(" << j.first << "," << j.second << ") ";
        }
        cout << endl;
    }
}

                                        //for no weight

//    void bfs(int start){
//        //making a queue
//	      queue <int> q;
//          int n=adj.size();
//          //making a visited array
//          bool visited[n]={false};
//
//          q.push(start);
//          visited[start]=true;
//
//          while(!q.empty()){
//            int curr=q.front();
//            cout<<curr<<" ";
//            q.pop();
//                for(auto neighbour:adj[curr]){
//                    if(!visited[neighbour]){
//                        q.push(neighbour);
//                        visited[neighbour]=true;
//                    }
//                }
//            }
//
//          }
          
//    void dfs(int start){
//    	stack<int> st;
//    	int n=adj.size();
//    	bool visited[n]={false};
//    	st.push(start);
//    	visited[start]=true;
//    	
//    	while(!st.empty()){
//    		int curr=st.top();
//    		cout<<curr<<" ";
//    		st.pop();
//    		for(auto neighbour :adj[curr]){
//    			if(!visited[neighbour]){
//    				st.push(neighbour);
//    				visited[neighbour]=true;
//				}
//			}
//		}
//    	
//    	
//	}

void bfs(int start) {
    // Making a queue
    queue<int> q;
    int n = adj.size();
    // Making a visited array
    vector<bool> visited(n, false);

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for (auto& neighbour : adj[curr]) {
            if (!visited[neighbour.first]) {
                q.push(neighbour.first);
                visited[neighbour.first] = true;
            }
        }
    }
}

void dfs(int start) {
    stack<int> st;
    int n = adj.size();
    vector<bool> visited(n, false);
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int curr = st.top();
        cout << curr << " ";
        st.pop();
        for (auto& neighbour : adj[curr]) {
            if (!visited[neighbour.first]) {
                st.push(neighbour.first);
                visited[neighbour.first] = true;
            }
        }
    }
}



};


int main() {
    int n,m;


    graph<int> g;
    // Adding edges to the graph
    g.addedge(1, 6, 1);
    g.addedge(1, 2, 1);
    g.addedge(5, 6, 1);
    g.addedge(2, 7, 1);
    g.addedge(5, 7, 1);
    g.addedge(5, 4, 1);
    g.addedge(3, 7, 1);
    g.addedge(4, 3, 1);


    g.print_adjlist();
    cout<<endl;
    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS starting from vertex " << startVertex << ":\n";
    g.bfs(startVertex);
    cout<<endl;
    cout << "DFS starting from vertex " << startVertex << ":\n";
    g.dfs(startVertex);
    cout<<endl;


    
    return 0;
}

