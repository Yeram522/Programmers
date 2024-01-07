#include <bits/stdc++.h>
using namespace std; 
const int n_max = 101;


int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int m,a[n_max][n_max],visited[n_max][n_max];

int ret = 1;
// #2648: 안전 영역
// 메모 : DFS 깊이 우선선 탐색 -> component 찾기기

void dfs(int y, int x, int d)
{
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++)
    {
        int ny,nx;
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(ny >= m || ny < 0 || nx >= m || ny < 0) continue;
        if(a[ny][nx] > d && !visited[ny][nx])
        {
            dfs(ny, nx,d);
        }
        
        
    }
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
   
    vector<int> results;
    //Input
    //1. 배열의 크기
    cin >> m;
    
    //2. 2차원 배열 입력 받기
    for(int i = 0; i < m ; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            cin >> a[i][j];
        }
    }

    // 최대 높이 많큼 비가 왔을 때 부터 기준치를 낮춰가며 안전구역개수의 최대 지점을 구함
    
    for(int d = 1; d < 101; d++)
    {
        //배열 초기화
        fill(&visited[0][0], &visited[0][0] + n_max * n_max , 0);
        int cnt = 0;
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
        	    if(a[i][j] > d && visited[i][j] == 0)
        	    {
        	        cnt++;
        	        dfs(i,j,d);
        	    }
            }
        } 
        
        //안전영역 최대 개수 갱신
        ret = max(ret,cnt);
    }
    
    // 디버깅 
    /*for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
        	cout << a[i][j] << ' '; 
        }
        cout << '\n';
    } */
    
    cout << ret << '\n';

    

    return 0;
    
} 