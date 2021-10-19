#include<bits/stdc++.h>
using namespace std;

int main()
{
	int cc_count = 0;	//number of connected components
	
	for(int i=1; i<=n; i++){
		if(visited[i] == 0){	//if the node is not visited
			dfs(i);
			cc_count++;
		}
	}
}
