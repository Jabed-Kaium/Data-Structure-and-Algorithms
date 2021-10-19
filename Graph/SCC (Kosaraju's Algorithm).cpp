//Strongly Connected Component (Kosaraju's Algorithm)
//Ref : CodeNCode (Youtube)
//Complexity : O(V+E)

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

const int MX = 1005;
vector<int> vec[MX];    //original graph
vector<int> tr[MX];     //reversed graph
vector<int> order;
vector<int> scc;
int vis[MX];

//dfs for ordering nodes
void dfs(int node){
    vis[node] = 1;
    for(int child : vec[node]){
        if(vis[child] == 0){
            dfs(child);
        }
    }
    order.push_back(node);
}

//dfs for finding SCC
void dfs1(int node){
    vis[node] = 1;
    for(int child : tr[node]){
        if(vis[child] == 0){
            dfs1(child);
        }
    }
    scc.push_back(node);
}

int main()
{
    int n,m,a,b,t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            vec[i].clear();
            tr[i].clear();
            vis[i] = 0;
        }
        order.clear();

        for(int i=1; i<=m; i++){
            cin>>a>>b;
            vec[a].push_back(b);
            tr[b].push_back(a);
        }

        //ordering nodes by increasing order of their out-time 
        for(int i=1; i<=n; i++){
            if(vis[i] == 0){
                dfs(i);
            }
        }

        for(int i=1; i<=n; i++){
            vis[i] = 0;
        }

        //calling dfs from the highest out-time node to find SCC
        for(int i=1; i<=n; i++){
            if(vis[order[n-i]] == 0){
                scc.clear();
                dfs1(order[n-i]);

                cout << "dfs1() called from " << order[n-i] << " and printing SCC : \n";
                for(int node : scc){
                    cout << node << " ";
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}