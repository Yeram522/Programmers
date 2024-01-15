// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
//#12869 뮤탈리스크
// "최소"의 시행으로 할 수 있는 조합 => BFS 최단 거리 알고리즘
// 9/3/1 3개 수의 조합이기 때문에 3차원 배열을 사용한다.

int N, visited[64][64][64], DP[64][64][64], a[3];

struct A
{
    int a,b,c;
};

//체력 감소 조합
int _a[6][3]={
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,9,3},
    {1,3,9}
};


queue<A> q;

int solve(int a, int b, int c) //매개변수 = 초기 SCV 체력력
{
    //처음
    visited[a][b][c] = 1;
    q.push({a,b,c});
    
    while(q.size())
    {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        
        //000에 도달했다면 break!
        if(visited[0][0][0]) break;
        
        
        for(int i = 0; i < 6; i++)
        {
            int na = max(0, a - _a[i][0]);
            int nb = max(0, b - _a[i][1]);
            int nc = max(0, c - _a[i][2]);
            
          
            
            if(visited[na][nb][nc]) continue;
            
            visited[na][nb][nc] = visited[a][b][c] + 1;
            
            q.push({na,nb,nc});
        }
    }
    
    
    
    return visited[0][0][0] - 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   //input
    cin >> N;
    
    for(int i = 0; i < N; i++)
    { cin >> a[i] ; }
    
    
    cout << solve(a[0],a[1],a[2]) << "\n";
    
    
    return 0;
}