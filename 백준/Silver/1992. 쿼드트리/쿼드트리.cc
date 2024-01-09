// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std; 
const int n_max = 70;

// #1992: 쿼드 트리
// 메모 : 탐색->구역 전체가 1 or 0이 아니면 -> 4분할 후 구역 탐색 = 재귀 + 전체탐색

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,  1, 0 , -1};
int N,sx,sy, ex,ey,a[n_max][n_max], visited[n_max][n_max];

//해당 범위 내의 1의 개수를 보고, 판단.
int dfs(int y, int x)
{
    visited[y][x] = 1; //방문처리
    
    int count = 0;
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < sy || ny > ey || nx < sx || nx > ex || visited[ny][nx] == 1) continue;
        
        count += a[ny][nx];
        
        count += dfs(ny, nx);
    }
    
    return count;
}

//quad tree라는 재귀 함수를 정의함
string quadtree(int n, int y, int x)
{
    //4분할로 나눠서 탐색
    string ret = "";
    // 범위 초기화화
    sy = y;//2
    sx = x;
    
    ey = y+n-1;
    ex = x+n-1;
   
    int starty = sy;
    int startx = sx;
    int endy = ey;
    int endx = ex;
    
    if( n == 1)
    {
        return to_string(a[y][x]);
    }
    //visited 초기화
    fill(&visited[0][0], &visited[0][0] + n_max*n_max, 0);
    
    int res = dfs(sy,sx) + (a[sy][sx] == 1 ? 1: 0);

    if(res == n*n || res == 0) //구역전체가 1또는 0이라면 string에 1또는 0 추가가
    {
        ret += (res == 0 ? "0" : "1");
    }
    else //아니라면 재귀!
    {
        int half = n/2;
        ret += "(";
        ret += quadtree(n/2, starty, startx );
        ret += quadtree(n/2, starty, startx + n/2 );
        ret += quadtree(n/2, starty + n/2 ,startx);
        ret += quadtree(n/2, starty + n/2,startx + n/2);
        ret += ")";
    }
    
    return ret;
    
}

int main() {
    //input
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }
    
    sy = 0;
    sx = 0;
    
    ey = N-1;
    ex = N-1;
    
    cout << quadtree(N, 0,0) ;


    

    return 0;
}