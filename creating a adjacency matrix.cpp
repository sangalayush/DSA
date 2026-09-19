#include<iostream>
#include<vector>
using namespace std;
int main(){
    int V,m;
    cin>>V>>m;
    int adj[V+1][V+1]={};
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //store the u->v & v->u edge in the matrix
        adj[u][v]=1;
        adj[v][u]=1;
    }
    cout<<adj[1][4];
    return 0;
}
//S.C.->O(N*N)
