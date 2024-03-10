#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<stack>
using namespace std;
template<class T>
class graph{
    public:
    map<T,list<T>> adj;
    
    void addedge(T u,T v){
        //cretae an edge u to v
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }

    void print_adjlist(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<"->";
            }
            cout<<endl;
        }
    }
    void bfs(int start){
        //making a queue
	      queue <int> q;//fifo
          int n=adj.size();
          //making a visited array
          bool visited[n]={false};

          q.push(start);
          visited[start]=true;

          while(!q.empty()){
            int curr=q.front();
            cout<<curr<<" ";
            q.pop();
                for(auto neighbour:adj[curr]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour]=true;
                    }
                }
            }

          }
          
    void dfs(int start){
    	stack<int> st;//lifo
    	int n=adj.size();
    	bool visited[n]={false};
    	st.push(start);
    	visited[start]=true;
    	
    	while(!st.empty()){
    		int curr=st.top();
    		cout<<curr<<" ";
    		st.pop();
    		for(auto neighbour :adj[curr]){
    			if(!visited[neighbour]){
    				st.push(neighbour);
    				visited[neighbour]=true;
				}
			}
		}
    	
    	
	}


};


int main() {
    int n,m;
    cout<<"enter the number of vertices"<<endl;
    cin>>n;

    cout<<"Enter the  jimbe rof edges"<<endl;
    cin>>m;

    graph<int> g;

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);

    }

    g.print_adjlist();
    cout<<endl;
    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS starting from vertex " << startVertex << ":\n";
    g.bfs(startVertex);


    
    return 0;
}

