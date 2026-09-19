#include <iostream>
#include<vector>
using namespace std;
void dfstraversal(int node, vector<int> adjList[], vector<int> &dfs, vector<int> &vis){
    vis[node]=1;
    dfs.push_back(node);
    for(auto it: adjList[node]){
        if(!vis[it]){
            dfstraversal(it,adjList,dfs,vis);
        }
    }
}
//T.C.->O(N)+O(2*E)->O(N)for each node the loop will run once
                    //and then for each node it will run for its 
                    //degree(means neighbor nodes)
//S.C.->O(N+N+N)->O(N)->for dfs traversal storing
                //O(N)->for visited array storing
                //O(N)->recurrsion stack space in worst case if the graph 
                //is a skewed graph like-1
                //                       |
                //                       2
                  //                     |
                   //                    3
                //                       |
                 //                      4
int main() {
    int V=8;
    vector<int> adjList[V+1];
    adjList[0]={};
    adjList[1]={2,3};
    adjList[2]={1,5,6};
    adjList[3]={1,4,7};
    adjList[4]={3,8};
    adjList[5]={2};
    adjList[6]={2};
    adjList[7]={3,8};
    adjList[8]={4,7};
    vector<int> dfs;
    vector<int> vis(V+1,0);
    int node=1;
    dfstraversal(node,adjList,dfs,vis);
    for(auto it:dfs)
        cout<<it<<" ";
    return 0;
}
