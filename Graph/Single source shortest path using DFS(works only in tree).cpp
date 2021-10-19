//Ref : CodeNCode (Youtube)

#include<bits/stdc++.h>
using namespace std;

vector <int> adj[7];
int distance_arr[7];
bool visited[7];

void dfs(int v,int dis){
    distance_arr[v] = dis;
    visited[v] = true;
    for(int i=0; i<adj[v].size(); i++){
        int u = adj[v][i];
        if(!visited[u]){
            dfs(u,dis+1);
        }
    }
}

int main(){
    
    int n=6,e=5;
    int a,b;
    while(e--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);   //source node as 1

    for(int i=1; i<=6; i++){
        cout << distance_arr[i] << " ";
    }

    return 0;
}