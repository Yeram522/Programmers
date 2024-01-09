// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std; 
const int n_max = 70;

// #1992: 쿼드 트리
// 메모 : 탐색->구역 전체가 1 or 0이 아니면 -> 4분할 후 구역 탐색 = 재귀 + 전체탐색

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,  1, 0 , -1};
int N,a[n_max][n_max];

//quad tree라는 재귀 함수를 정의함
string quadtree(int n, int y, int x)
{
    if( n == 1)
    {
        return to_string(a[y][x]);
    }
    
    int b = a[y][x];
    
    string ret = "";

    for(int i = y; i < y + n ; i++)
    {
        for(int j = x; j < x + n; j++)
        {
            if(b != a[i][j])
            {
                int half = n/2;
                ret += "(";
                ret += quadtree(half, y, x );
                ret += quadtree(half, y, x + half );
                ret += quadtree(half, y + half ,x);
                ret += quadtree(half, y + half,x + half);
                ret += ")";
                
                return ret;
            }
        }
    }
   
    return to_string(a[y][x]);
    
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

    
    cout << quadtree(N, 0,0) ;


    

    return 0;
}