#include<bits/stdc++.h>
using namespace std;
#define int         long long
#define endl        "\n"
#define ff          first
#define ss          second
#define pb          push_back
#define mp          make_pair
#define yes         cout<<"YES\n"
#define no          cout<<"NO\n"
#define clr(a)      memset(a,0,sizeof(a))
#define reset(a)    memset(a,-1,sizeof(a))
#define mod         1000000007
#define pi          acos(-1)
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);

// int dx[] = { -1 , 0 , 1 , 0};
// int dy[] = {0 , 1 , 0 , -1};

// for chess knight move
// int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

signed main()
{
// #ifndef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
// #endif

    vector<int> adj[10];
    bool vis[10] = {0};

    adj[0].pb(1);
    adj[0].pb(2);
    adj[0].pb(3);

    adj[1].pb(4);
    adj[1].pb(5);

    adj[2].pb(6);

    adj[3].pb(7);

    stack<int> s;

    s.push(0);
    vis[0] = true;

    cout << s.top() << "-->";

    while(!s.empty()) {
    	int curr = s.top();
    	bool flag = false;

    	for(int i=0; i<adj[curr].size(); i++) {
    		int child = adj[curr][i];
    		if(!vis[child]) {
    			vis[child] = true;
    			cout << child << "-->";
    			s.push(child);
    			flag = true;
    			break;
    		}
    	}

    	if(flag)continue;
    	else s.pop();
    }

    return 0;
}