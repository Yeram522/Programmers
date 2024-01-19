// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int N,C, a[1004];
vector<pair<int,int>> v;
map<int,int> mp, mp_first;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first == b.first)
    {
        return mp_first[a.second] < mp_first[b.second];
    }
    
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //input
    cin >> N >> C;
    
    for(int i = 0; i < N; i++)
    {
        cin >> a[i]; mp[a[i]]++;//카운팅
        if(mp_first[a[i]] == 0) mp_first[a[i]] = i + 1; //숫자의 순서!
    }
    
    for(auto it : mp)
    {
        v.push_back({it.second,it.first});
    }
    
    sort(v.begin(), v.end(),cmp);
    
    for(auto i : v)
    {
        for(int j = 0; j < i.first;j++)
        {
            cout << i.second << " ";
        }
    }
    
    return 0;
}