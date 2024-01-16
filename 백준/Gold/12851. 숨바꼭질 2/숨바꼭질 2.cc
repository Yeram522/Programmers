// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
//#12851: 숨바꼭질 2
int N,K;
int visited[100005];
long long cnt[100005];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //Input
    cin >> N >> K;
    
    if(N == K)
    {
        puts("0"); puts("1");
        
        return 0;
    }
    //BFS
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    cnt[N] = 1;
    
    while(!q.empty())
    {
        int now = q.front(); q.pop();
        
        for(int next : {now - 1, now + 1, now*2})
        {
            if(0 <= next && next <= MAX)
            {
                if(!visited[next]) //방문 X
                {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                }
                else if(visited[next] == visited[now] + 1)
                {
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    
    cout << visited[K] - 1 << "\n";
    cout << cnt[K]  << "\n";

    return 0;
}