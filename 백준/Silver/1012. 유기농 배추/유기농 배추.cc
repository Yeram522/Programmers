#include <bits/stdc++.h>
using namespace std; 
const int n_max = 51;


int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int m,n,a[n_max][n_max],visited[n_max][n_max];
// #1012: 유기농 배추추
// 메모 : DFS 깊이 우선선 탐색 -> component 찾기기

void dfs(int y, int x)
{
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++)
    {
        int ny,nx;
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(ny >= n || ny < 0 || nx >= m || ny < 0) continue;
        if(a[ny][nx] == 0 || visited[ny][nx] == 1) continue;
        
        dfs(ny, nx);
    }
}
int main()
{
    int T,K; //testcase, 배추 개수
    int res = 0;
    
    vector<int> results;
    //Input
    //1. Test case의 개수
    scanf("%d", &T);
    
    //2. Test case 개수만큼 case 입력 받기
    for(int i = 0; i < T ; i++)
    {
        scanf("%d %d %d", &m,&n,&K);
        for(int j = 0; j < K ; j ++) //배추 개수만큼 위치 입력 받기
        {
            int x, y;
            scanf("%d %d", &x, &y);
            a[y][x] = 1; // 배추 위치는 1로 변경.
            
        }
        
        //3. DFS
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
        	    if(visited[i][j] == 0 && a[i][j] == 1)
        	    {
        	      res++; 
        	      dfs(i,j);
        	    }
            }
        }
        
        results.push_back(res);
        fill(&a[0][0],&a[0][0] + 51*51, 0);
        fill(&visited[0][0],&visited[0][0] + 51*51, 0);
        res = 0; // temp res 초기화
    }


    
    // 디버깅 
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        	cout << a[i][j] << ' '; 
        }
        cout << '\n';
    } */
    
    for(int i = 0; i < results.size() ; i ++)
    {
         cout << results[i] << endl;
    }
   
    

    return 0;
    
} 