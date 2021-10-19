//BFS
//Ref : CodeNCode (Youtube)

#include<bits/stdc++.h>
using namespace std;

vector <int> adj[10005];
bool visited[10005];
int dis[10005];     //dis[i] is the shortest path of i'th node from source

void bfs(int source){   //source node
    queue <int> q;
    q.push(source);
    visited[source] = true;
    dis[source] = 0;    //distance from source to source = 0

    while(!q.empty()){
        int curr = q.front();   //current node
        q.pop();

        for(int i=0; i<adj[curr].size(); i++){  //traverse all the adjacent nodes of current node
            int child = adj[curr][i];
            if(!visited[child]){
                q.push(child);
                dis[child] = dis[curr] + 1;
                visited[child] = true;
            }
        }
    }
}

int main()
{   
    int n,m,a,b;
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);     //pass 1 as source node

    cout << dis[n] << "\n";     //shortest path from source to n'th node

    return 0;
}