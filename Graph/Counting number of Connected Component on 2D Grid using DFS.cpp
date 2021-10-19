//Counting number of Connected Component on 2D Grid using DFS
//Ref : CodeNCode (Youtube)

#include<bits/stdc++.h>
using namespace std;

int N,M;
int ar[1001][1001];     //input grid
bool visited[1001][1001];

bool isValid(int x,int y){
    if(x < 1 || x > N || y < 1 || y > M)
    return false;

    if(visited[x][y] == true || ar[x][y] == 0)
    return false;

    return true;
}

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

void dfs(int x,int y){
    visited[x][y] = true;

    for(int i=0; i<4; i++){
        if(isValid(x + dx[i] , y + dy[i]))
        dfs(x + dx[i] , y + dy[i]);
    }
}

int main()
{
    cin>>N>>M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>ar[i][j];
        }
    }

    int cc = 0;     //count of connected component

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(visited[i][j] == 0 && ar[i][j] == 1){    //if the cell is not visited yet & it is not 0
                cc++;
                dfs(i,j);
            }
        }
    }

    cout << "CC : " << cc << "\n";

    return 0;
}