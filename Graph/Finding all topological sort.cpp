//Finding all topological sort

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
int in[MX]; //in-degree

void allTopSort(vector<int>& res , int vis[] , int n){
    bool flag = false;
    for(int i=1; i<=n; i++){
        if(in[i] == 0 && !vis[i]){
            for(int node : vec[i]){
                in[node]--;
            }

            res.push_back(i);
            vis[i] = 1;
            allTopSort(res,vis,n);

            //backtracking
            vis[i] = 0;
            res.pop_back();
            for(int node : vec[i]){
                in[node]++;
            }

            flag = true;
        }
    }

    if(!flag){
        for(int node : res){
            cout << node << " ";
        }
        cout << "\n";
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

    vector<int> res;
    int vis[n+1];
    clr(vis);

    allTopSort(res , vis , n);

    return 0;
}