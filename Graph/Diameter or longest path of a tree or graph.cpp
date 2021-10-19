#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
bool visited[10005];
int maxLength = INT_MIN,maxNode = 0;

void dfs(int v,int c){
	visited[v] = true;
    if(c > maxLength){  //if current length > previous length
        maxLength = c;
        maxNode = v;
    }
	for(int i=0; i<adj[v].size(); i++){
        int u = adj[v][i];
		if(!visited[u]){
			dfs(u,c+1);
		}
	}
}

int main()
{
    
    int n,a,b;

    cin>>n;
    n--;

    while(n--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);
    maxLength = INT_MIN;
    memset(visited,0,sizeof(visited));  //clear visited array
    dfs(maxNode,0);

    cout << maxLength << "\n";

    return 0;
}
