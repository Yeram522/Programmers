// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> numbs;
string s;
string ret;
void go()
{
    while(true)
    {
        if(ret.size() && ret.front() == '0') ret.erase(ret.begin());
        else
            break;
    }
    
    if(ret.size() == 0) ret = "0";
    
    numbs.push_back(ret);
    ret = "";
    
    return;
}

bool cmp(string a,string b)
{
    if(a.size() == b.size()) return a<b;
    return a.size() < b.size();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i  = 0; i < N; i++)
    {
        cin >> s;
        ret = "";
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] <  65) ret+=s[j];
            else if(ret.size()) go();
        }
        if(ret.size()) go();
        
    }
    
    //문자를 숫자로 바꾸기
    sort(numbs.begin(), numbs.end(),cmp);
    for(auto num : numbs)
    {
        cout << num << endl;
    }
    return 0;
}