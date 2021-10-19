//Cycle detection using DFS
//Ref : CodeNCode (Youtube)
//returns true if any cycle found,otherwise false if not found
//for first call,pass node = 1 & parent = -1

bool dfs(int node,int parent){
    visited[node] = true;

    for(int i=0; i<adj[node].size(); i++){
        int child = adj[node][i];
        
        if(visited[child] == 0){    //if not visited,make dfs call
            if(dfs(child,node) == true){
                return true;
            }
        }
        else{
            if(child != parent){    //if visited check it is parent or not
                return true;
            }
        }
    }
    return false;
}