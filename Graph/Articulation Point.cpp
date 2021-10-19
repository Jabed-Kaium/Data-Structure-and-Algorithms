//Articulation Point / Cut vertex
//Ref : CodeNCode (Youtube)
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

const int MX = 101;
vector<int> vec[MX];
int in[MX] , low[MX] , vis[MX];
int timer = 1;

void dfs(int node,int par = -1){
    vis[node] = 1;
    in[node] = low[node] = timer++;

    int children = 0;   //subtree count of current node

    for(int child : vec[node]){
        if(child == par)continue;
        if(vis[child] == 1){
            //edge (node - child) is a back edge
            low[node] = min(low[node] , in[child]);
        }
        else{
            //edge (node - child) is a forward edge
            dfs(child , node);
            low[node] = min(low[node] , low[child]);
            if(low[child] >= in[node] && par != -1){
                IS_CUTPOINT(node);  //actually node is an articulation point.We can add it in a set if we calculate total number of A.P in graph
            }
            ++children;
        }
    }

    if(par == -1 && children > 1){
        IS_CUTPOINT(node);  //if root has more than 1 subtree,then it's an A.P
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

    //check for all connected components
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    return 0;
}