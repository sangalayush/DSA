#include<iostream>
#include<vector>
using namespace std;
int main(){
    int V,m;
    cin>>V>>m;
    vector<int> adjList[V+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //for undirected graph
        //store the u->v 
        //and v->u
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    //S.C.->O(2*E)
    int a;
    cin>>a;
    for(auto it: adjList[a])
        cout<<it<<" ";
    return 0;
}
//---------------------------------------------------------------------
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int V,m;
    cin>>V>>m;
    vector<int> adjList[V+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //for directed graph
        //store the u->v 
        adjList[u].push_back(v);
    }
    //S.C.->O(E)
    int a;
    cin>>a;
    for(auto it: adjList[a])
        cout<<it<<" ";
    return 0;
}
