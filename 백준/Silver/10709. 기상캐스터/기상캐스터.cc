// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
const int n_max = 105;
int W,H;
char mp[n_max][n_max];
int mp_i[n_max][n_max];
bool flag = false;
int _time;
int main() {

    cin >> W >> H;
    
    for(int i  = 0; i < W; i++)
    {
        flag = false;
        _time = 0;
        for(int j  = 0; j < H; j++)
        {
            cin >> mp[i][j];
            
            if(!flag && mp[i][j] == '.') mp_i[i][j] = -1;
            else if(mp[i][j] == 'c')
            {
                flag = true;
                mp_i[i][j] = 0;
                _time = 0;
                _time ++;
            }
            else if(flag && '.')
            {
                mp_i[i][j] = _time++;
            }
            
        }
    }

    for(int i  = 0; i < W; i++)
    {
        for(int j  = 0; j < H; j++)
        {
            cout << mp_i[i][j] << " ";
        }
        cout<<"\n";
    }
    
    return 0;
}