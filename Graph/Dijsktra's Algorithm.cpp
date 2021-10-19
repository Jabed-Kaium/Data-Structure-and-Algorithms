//Ref : CodeNCode (Youtube)
//node starts from 1-N

#include<bits/stdc++.h>

using namespace std;

vector < pair<int,int> > adj[1001]; //adjacency list which holds adjacent vertex & weight

int main()
{
    int n,m,a,b,w;
    cin>>n>>m;

    while(m--){
        cin>>a>>b>>w;   //input edge & its weight
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;    //min-heap

    vector<int> dist(n+1 , INT_MAX);    //distance array
    pq.push({0,1});  //push source node & its distance(node = 1, distance = 0)
    dist[1] = 0;    //update distance of source node

    while(!pq.empty()){
        int curr = pq.top().second;     //current node
        int curr_d = pq.top().first;    //distance of current node
        pq.pop();

        for(int i=0; i<adj[curr].size(); i++){  //traverse all adjacent node of current node
            pair<int,int> edge = adj[curr][i];

            if(curr_d + edge.second < dist[edge.first]){    //if current path < previous path
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first],edge.first});
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << dist[i] << " ";
    }

    return 0;
}