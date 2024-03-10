#include<iostream>
#include<list>
#include<map>
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


};

int main() {
    int n,m;
    cout<<"enter the number of vertices"<<endl;
    cin>>n;

    cout<<"Enter the  number of edges"<<endl;
    cin>>m;

    graph<int> g;

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);

    }

    g.print_adjlist();
    
    return 0;
}

