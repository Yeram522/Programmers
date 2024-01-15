// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

//#2589 보물섬
const int n_max = 55;
int N, L , R ;
int visited[n_max][n_max]; //방문리스트
vector<pair<int,int>> nationgroup;//연합국가리스트
int a[n_max][n_max]; //맵맵

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int _sum = 0;
int result = 0;

void DFS(int y, int x,vector<pair<int,int>> &nationgroup)
{
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        int gap = abs(a[y][x] - a[ny][nx]); //차이 절대값
        if(ny < 0 || ny >= N || nx <0 || nx >= N ) continue;
        if( visited[ny][nx] ) continue; //방문여부
        if( L > gap || R < gap ) continue; //인구차이가 범위 밖이면 국경 열리지 X
        visited[ny][nx] = 1;
        _sum += a[ny][nx];
        nationgroup.push_back({ny,nx});
    
        DFS(ny, nx , nationgroup);
    }
    
    return;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   //input
    cin >> N >> L >> R;
    
    for(int i = 0 ; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    }
    
    
    
    while(true)
    {
       
        bool flag = 0;
        fill(&visited[0][0] , &visited[0][0] + n_max*n_max,0);
        for(int i = 0 ; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                //초기화
                if( visited[i][j] ) continue;
                nationgroup.clear();
                visited[i][j] =1 ;
                _sum = a[i][j];
                nationgroup.push_back({i,j});
                DFS(i,j,nationgroup);
                
            
            
                if(nationgroup.size() == 1) continue;
  
                for(pair<int,int> p : nationgroup)
                {
                    a[p.first][p.second] = _sum / nationgroup.size();
                    flag = 1;
                }
                
            }
        }
        
        if(!flag) break;
        result ++;
    }

    
    
    cout << result;
    return 0;
}