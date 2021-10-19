//BFS on 2D Grid
//Ref : CodeNCode (Youtube)

#include<bits/stdc++.h>
using namespace std;

int dist[1001][1001];
int N,M;
bool visited[1001][1001];

bool isValid(int x,int y){
    if(x < 1 || x > N || y < 1 || y > M)    //if the cell is outside of grid
    return false;

    if(visited[x][y] == 1)  //if the cell is already visited
    return false;

    return true;
}

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

void bfs(int srcX,int srcY){
    queue< pair<int,int> > q;
    q.push({srcX,srcY});
    visited[srcX][srcY] = 1;
    dist[srcX][srcY] = 0;   //distance of source to source  = 0

    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){     //check all adjacent cell
            if(isValid(currX + dx[i] , currY + dy[i])){
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                dist[newX][newY] = dist[currX][currY] + 1;  //update distance
                visited[newX][newY] = 1;
                q.push({newX , newY});
            }
        }
    }

    //print distance from source to all other cell
    cout << "Distance Array : \n";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int x,y;
    cin>>N>>M;  //rows & columns
    cin>>x>>y;  //source cell
    bfs(x,y);

    return 0;
}