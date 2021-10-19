//Ref : CodeNCode (Youtube)
/*if the function returns true then it is bipartite,
  otherwise not
*/

bool dfs(int v,int c){
    visited[v] = true;  //mark the node as visited
    col[v] = c; //colour the node by c

    for(int i=0; i<adj[v].size(); i++){
        int child = adj[v][i];

        if(!visited[child]){
            if(dfs(child , c^1) == false){
                return false;
            }
        }
        else{
            if(col[v] == col[child]){
                return false;
            }
        }
    }
    return true;
}