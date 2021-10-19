//Finding Bridges
//Ref : CodeNCode(Youtube)
//Complexity : O(n+m)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

vector <int> vec[101];
int in[101] , low[101] , vis[101] , timer=0;

void dfs(int node, int par){
    vis[node] = 1;
    in[node] = low[node] = timer++;

    for(int child : vec[node]){
        if(child == par)continue;

        if(vis[child] == 1){
            //edge (node-child) is a back edge
            
            low[node] = min(low[node] , in[child]);
        }
        else{
            //edge (node-child) is a forward edge
            dfs(child , node);
            
            if(low[child] > in[node])
            cout << node << " - " << child << " is a bridge\n";
            
            low[node] = min(low[node] , low[child]);
        }
    }
}

int main()
{
    int n,m,a,b;
    cin>>n>>m;

    while(m--){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    dfs(1,-1);

    return 0;
}