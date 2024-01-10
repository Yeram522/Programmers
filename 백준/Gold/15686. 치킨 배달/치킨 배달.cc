// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
// 정의의
#define Blank 0
#define House 1
#define Chicken 2

//#15686 치킨 배달

const int n_max = 52;

int N,M,a[n_max][n_max];
vector<vector<int>> chickenList;
vector<pair<int,int>> chicken; //치킨집 리스트 
vector<pair<int,int>> _home; //집 리스트


void combi(int start, vector<int> v)
{
    //최대 M개를 고르면 return
    if(v.size() == M)
    {
        chickenList.push_back(v);
        return;
    }

    for(int i = start + 1; i < chicken.size(); i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
    //input
    cin >> N >> M;
    
    for(int i = 0; i < N;i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> a[i][j];
            
            //치킨이면 좌표 저장
            if(a[i][j] == Chicken)
            {
                chicken.push_back({i,j});
            }
            else if(a[i][j] == House)
            {
                _home.push_back({i,j});
            }
        }
    }
    
    vector<int> v; 
    int result = 987654321; //치킨 거리 최소값

    combi(-1,v);
    
    for(vector<int> CList : chickenList)
    {
        int ret = 0;
        for(pair<int,int> j : _home)
        {
            int _min = 987654321;
            for(int ch : CList)
            {
                _min = min( _min, abs(chicken[ch].first - j.first)+abs(chicken[ch].second - j.second));
            }
            ret += _min;
        }
        
        result = min(result, ret);
    }
    

    cout << result;
    
    return 0;
}