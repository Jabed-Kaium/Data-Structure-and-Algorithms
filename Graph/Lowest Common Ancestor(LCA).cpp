//Lowest Common Ancestor(LCA)
//Ref : CodeNCode (Youtube)
//Complexity : O(q * logn)

#include<bits/stdc++.h>
using namespace std;

vector <int> adj[1001]; //adjacency list
const int maxN = 10;    //maxN = log2(N)
int level[1001];
int LCA[1001][maxN+1];    //sparse table

/*by dfs , set the level of each node
  & set the 0'th column of LCA table
*/
void dfs(int node,int lvl,int par){
    level[node] = lvl;
    LCA[node][0] = par;

    for(int i=0; i<adj[node].size(); i++){
        int child = adj[node][i];
        if(child != par){
            dfs(child, lvl+1, node);
        }
    }
}

void init(int n){
    dfs(1,0,-1);    //root = 1,so level of root = 0 & parent of root = -1

    //fill the LCA table column by column
    for(int j=1; j<=maxN; j++){
        for(int i=1; i<=n; i++){
            if(LCA[i][j-1] != -1){
                int par = LCA[i][j-1];
                LCA[i][j] = LCA[par][j-1];
            }
        }
    }
}

int getLCA(int a,int b){
    if(level[b] < level[a]){    //make b deeper
        swap(a,b);
    }

    int d = level[b] - level[a];

    //get a & b at same level
    while(d > 0){
        int i = log2(d);
        b = LCA[b][i];
        d -= (1 << i);
    }

    if(a == b)return a;

    for(int i=maxN; i>=0; i--){
        if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i])){
            a = LCA[a][i] , b = LCA[b][i];
        }
    }

    return LCA[a][0];
}

int main()
{
    int n,a,b,q;

    memset(LCA,-1,sizeof(LCA));

    cin>>n;

    for(int i=1; i<n; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init(n);

    cin>>q;

    while(q--){
        cin>>a>>b;
        cout << getLCA(a,b) << "\n";
    }

    return 0;
}