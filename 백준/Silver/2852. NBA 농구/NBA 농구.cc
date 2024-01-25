// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int N; //개수

vector<pair<int,int>> _time;
vector<int> winingteam;
int score[2];

pair<int,int> cal(int t, int m, int st, int sm)
{
    int rt = st - t;
    int rm;
    if(m > sm)
    {
        rt -= 1;
        
        rm = sm+60-m;
    }
    else
        rm = sm - m;
    return {rt,rm};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력력 개수
    cin >> N;
    
    winingteam.push_back(0);
    
    for(int i = 0; i < N; i++)
    {
        int iteam;
        string stime;
        cin >> iteam >> stime;
        
        //기록 저장.
        _time.push_back({stoi(stime.substr(0,2)),stoi(stime.substr(3,2))});
        
        //이긴팀에 점수 추가.
        score[iteam-1] ++;
        
        if(score[0] == score[1])
            winingteam.push_back(0);
        else if(score[0] > score[1])
            winingteam.push_back(1);
        else
            winingteam.push_back(2);
    }
    _time.push_back({48,0});
    
    vector<pair<int,int>> res= {{0,0},{0,0}};
    int idx = -1;
    for(auto team : winingteam)
    {
        idx++;
        if(team <= 0) { continue;}
        
        pair<int,int> ret = cal(_time[idx-1].first, _time[idx-1].second,_time[idx].first, _time[idx].second);
        res[team - 1].first += ret.first;
        res[team - 1].second += ret.second;
       
    }
    
    for(int i = 0; i < 2; i++)
    {
        if(res[i].second/60 != 0)
        {
            res[i].first += res[i].second/60;
            res[i].second = res[i].second%60;
        }
        string time = res[i].first/10 == 0 ? "0" + to_string(res[i].first) :to_string(res[i].first);
        string min = res[i].second/10 == 0 ? "0" + to_string(res[i].second) :to_string(res[i].second);
        cout << time << ":" <<min<<"\n";
    }
    
    
    return 0;
}