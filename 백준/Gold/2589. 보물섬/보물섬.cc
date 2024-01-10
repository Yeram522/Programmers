// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

//#2589 보물섬
const int n_max = 55;
int N, M ; vector<pair<int,int>> land; vector<vector<int>> treasureList;
int visited[n_max][n_max]; //방문리스트트
char a[n_max][n_max]; //맵맵

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int res = 0;

void BFS(int y, int x)
{
    fill(&visited[0][0], &visited[0][0] + n_max*n_max,0);
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = 1;

    while(q.size())
    {
        tie(y,x) = q.front();
        q.pop();
            
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
        
            if(ny< 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] == 'W') continue;
            if(visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
            
            res = max(res, visited[ny][nx]);
        }
    }
        
        
    
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   //input
    cin >> N >> M;
    
    for(int i = 0 ; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }
    
    for(int i = 0 ; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(a[i][j] == 'L')
                {  BFS(i,j); }
        }
    }
    
    cout << res - 1;
    return 0;
}