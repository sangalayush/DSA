#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> bfstraversal(int V,vector<int> adjList[]){
    queue<int> q;
    vector<int> vis(V,0);
    vector<int> bfs;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int node= q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adjList[node]){
        if(!vis[it]){
            vis[it]=1;
            q.push(it);
        }
        }
    }
    return bfs;
}
//T.C.->O(V+2E)->bcs each node is traversed once and in an undirected graph the neighboring nodes are also checked for each node. ie. 2*E
//S.C.->O(N+N)-> N for storing vis array and returning bfs array and if exempt taking adjList for giving the input.
int main() {
    int V=5;
    vector<int> adjList[5];
    adjList[0]= {1, 2};
    adjList[1]= {0, 3};
    adjList[2]= {0, 4};
    adjList[3]= {1};
    adjList[4]= {2};
    vector<int> result= bfstraversal(V,adjList);
    for(auto it:result)
        cout<<it<<" ";
    return 0;
}
