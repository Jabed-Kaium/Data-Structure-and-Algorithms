//Topological Sort using DFS

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

const int MX = 105;
vector<int> vec[MX];
bool vis[MX];
vector<int> ans;

void dfs(int node){
    vis[node] = 1;
    for(int child : vec[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
    ans.push_back(node);
}

void topological_sort(int n){
    clr(vis);
    ans.clear();
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(ans.begin() , ans.end());
}

int main()
{
    int n,m,a,b;
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        vec[a].push_back(b);
    }

    topological_sort(n);

    for(int v : ans)cout << v << " ";


    return 0;
}