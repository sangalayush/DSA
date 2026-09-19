#include<iostream>
#include<vector>
using namespace std;
void dfs(int node, vector<int> adjList[], int vis[]){
    vis[node]=1;
    for(auto neighbor: adjList[node]){
        if(!vis[neighbor])
            dfs(neighbor,adjList,vis);
    }
}
int numberofprovinces(int V, vector<vector<int>>adj, int vis[]){
    vector<int> adjList[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1 && i!=j){
                adjList[i].push_back(j);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjList,vis);
        }
    }
    return cnt;
}
//T.C.->O(N)+O(N+2*E)->but in best case if it were N different provinces then it would have been O(N)+O(N)~~O(N).
//S.C.->O(N)+O(N)->For storing visited array and we are using a recurrsion stack space & if we exempt the adj matrix as it is already given in problems.
int main(){
    int V;
    cin>>V;
    vector<vector<int>> adj={{1,0,1},{0,1,0},{1,0,1}};
    int vis[V]={0};
    cout<<"Number of provinces: "<<numberofprovinces(V,adj,vis);
    return 0;
}
