//DFS on 2D grid
//Ref : CodeNCode (Youtube)

#include<bits/stdc++.h>
using namespace std;

int N,M;
int visited[1001][1001];

bool isValid(int x,int y){
    if(x < 1 || x > N || y < 1 || y > M)    //outside of grid
    return false;

    if(visited[x][y] == true)   //if already visited
    return false;

    return true;
}

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

void dfs(int x,int y){
    visited[x][y] = true;

    cout << x << " " << y << "\n";  //printing path

    for(int i=0; i<4; i++){
        if(isValid(x + dx[i] , y + dy[i]))
        dfs(x + dx[i] , y + dy[i]);
    }
}

int main()
{
    cin>>N>>M;

    dfs(1,1);

    return 0;
}