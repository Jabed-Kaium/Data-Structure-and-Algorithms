//Topological Sort (Kahn's Algorithm)
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

vector<int> vec[101];
int in[101];    //count in-degree
vector<int> res;    //result array

void kahn(int n){
    queue <int> q;
    for(int i=1; i<=n; i++){
        if(in[i] == 0)q.push(i);
    }

    while(!q.empty()){
        int curr = q.front();
        res.push_back(curr);
        q.pop();

        for(int node : vec[curr]){
            in[node]--;
            if(in[node]==0){
                q.push(node);
            }
        }
    }

    //print sorted list
    cout << "TopSort : ";
    for(int node : res){
        cout << node << " ";
    }
}

int main()
{
    int n,m,a,b;
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        vec[a].push_back(b);
        in[b]++;
    }

    kahn(n);

    return 0;
}