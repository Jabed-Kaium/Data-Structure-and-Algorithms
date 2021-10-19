//Sub-tree size using DFS in O(N)
//Ref : CodeNCode (Youtube)

#include<bits/stdc++.h>
using namespace std;

vector <int> adj[100005];
bool visited[100005];
int subSize[100005];    //sub-tree size of i'th node

int dfs(int node){
    visited[node] = true;
    int curr_size = 1;  //intial value of sub-tree size of node = 1 (node itself)

    for(int i=0; i<adj[node].size(); i++){
        int child = adj[node][i];
        if(visited[child] == 0){
            curr_size += dfs(child);    //add the sub-tree size of its child node
        }
    }

    subSize[node] = curr_size;  //update size
    return curr_size;
}

int main()
{
    int n,a,b;

    cin>>n;
    for(int i=1; i<n; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //call dfs(1) when 1 is root, if another node is root tha pass that node
    dfs(1);

    for(int i=1; i<=n; i++){
        cout << "Sub-tree size of node " << i << " is " << subSize[i] << "\n";
    }

    return 0;
}