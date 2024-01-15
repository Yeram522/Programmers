// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
//#2589 보물섬
const int n_max = 1004;
int R , C;
int y, x, jy, jx;
int person_check[n_max][n_max],fire_check[n_max][n_max]; //방문리스트
char a[n_max][n_max]; //맵맵

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int result = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   //input
    cin >> R >> C ;
    
    //중요!
    fill(&fire_check[0][0], &fire_check[0][0] + n_max*n_max,INF);
    
    queue<pair<int,int>> q;
    
    for(int i = 0; i < R ; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> a[i][j];
            
            if(a[i][j] == 'J')
            {   jy = i; jx = j;  }
            
            else if(a[i][j] == 'F')
            {  fire_check[i][j] = 1; q.push({i,j}); }
        }
    }
    
    //BFS(깊이 우선 탐색)
    //Fire check
    while(q.size())
    {
        tie(y,x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= R || nx < 0 || nx >= C ) continue;

            if(fire_check[ny][nx] != INF|| a[ny][nx] == '#') continue;
            
            fire_check[ny][nx] =  fire_check[y][x] + 1;
            
            q.push({ny,nx});
            
        }
    }
    
    
    person_check[jy][jx]  = 1; 
    q.push({jy,jx});
    
    while(q.size())
    {
        tie(y,x) = q.front(); q.pop();
        
         // 가장자리 접한 공간일 경우에 탈출한다.
        if( x == 0 || y == 0 || y == R-1 || x == C-1 )
        {
            result = person_check[y][x];
            break;
                
        }
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= R || nx < 0 || nx >= C || a[ny][nx] == '#') continue;
            if( person_check[ny][nx] ) continue;
            if(fire_check[ny][nx] <= person_check[y][x] + 1) continue;
            
            person_check[ny][nx] =  person_check[y][x] + 1;
            
           
                
            q.push({ny,nx});
            
        }
    }

    if(result != 0)cout << result << "\n";
    else
    cout<< "IMPOSSIBLE" << "\n";
    
    return 0;
}