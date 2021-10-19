//Ref : CodeNCode + Shafayet Ashraf's book
//Complexity : O(n*m)

#include<bits/stdc++.h>
using namespace std;

struct edge {
    int a, b, cost;
};

const int MX = 100005;
const int INF = 1000000000;
int n, m, src;
vector<edge>e;  //edge list
vector<int> dis(MX, INF);   //distance array

bool bellman_ford()
{
    dis[src] = 0;

    //run for n-1 phases
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dis[e[j].a] + e[j].cost < dis[e[j].b]) {    //if distance < current distance
                dis[e[j].b] = dis[e[j].a] + e[j].cost;
            }
        }
    }

    //if distance can be updated after n-1 phases, it contains negative cycle
    for (int i = 0; i < m; i++) {
        if (dis[e[i].a] + e[i].cost < dis[e[i].b]) {
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> n >> m >> src;
    for (int i = 0; i < m; i++) {
        struct edge tmp;
        cin >> tmp.a >> tmp.b >> tmp.cost;
        e.push_back(tmp);
    }
    bool ans = bellman_ford();
    if (ans) {
        cout << "Have no negative cycle\n";

        //distance of each node from source
        for(int i=1; i<=n; i++){
            cout << dis[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "Have negative cycle\n";
    }

    return 0;
}