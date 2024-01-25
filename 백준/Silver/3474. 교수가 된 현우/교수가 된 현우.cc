// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //문제 개수
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        int N; //팩토리얼
        
        cin >> N;
        int ret2 = 0; int ret5 = 0;
        for(int j = 2; j <= N;j*=2)
        {
                ret2 += N/j;
        }
        
        for(int k = 5; k <= N; k*=5)
        {
            ret5 += N/k;
        }
        
        cout << min(ret2,ret5) <<"\n";
    }
    return 0;
}