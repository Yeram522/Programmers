// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std; 

int N, M, J;
int apple[25]; //사과 위치치
int bucket = 0; //바구니 위치치
int res = 0; //이동거리

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    
    cin >> N >> M ;
    cin >> J;
    
    for(int i = 0; i < J ; i++)
    {
        cin >> apple[i];
    }
    
    for(int i = 0; i < J; i++)
    {
        int dis = 0;
        
        if(bucket + M < apple[i])
        {
            dis = apple[i] - M - bucket;
            
            bucket = apple[i] - M;
        }
        else if( apple[i] <= bucket)
        {
            dis = bucket - (apple[i] - 1 );
            
            bucket = apple[i] - 1;
        }
        
        //cout << dis << endl;
        
        res += (dis >= 1 ? dis : 0);
    }
    
    cout << res;

    return 0;
}