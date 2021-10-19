//In Out time of nodes
//Ref : CodeNCode (Youtube)

int timer = 1;
bool dfs(int v){
    visited[v] = true;
    in[v] = timer++;    //set in-time

    for(int i=0; i<adj[v].size(); i++){
        int child = adj[v][i];

        if(visited[child] == 0){
            dfs(child);
        }
    }
    out[v] = timer++;   //set out-time
}