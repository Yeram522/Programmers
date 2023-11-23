// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        
    int N, M;
    
    map<string, int> namekey; //<Name, index>
    vector<string> indexkey; //<index, Name>
    
    vector<string> results;
    
    //N 포켓몬 개수 , M 문제 수
    cin >> N >> M;
    
    for(int i = 0; i < N ; i ++)
    {
        string pockename;
        cin >> pockename;
        namekey.insert( pair<string, int>(pockename, i ));
        indexkey.push_back(pockename);
    }
    
    for(int i = 0; i < M ; i ++)
    {
        string quiz;
        cin >> quiz;
    
        //대문자 및 소문자 구분보다 숫자인지 구분이 간단하기 때문에 숫자 인가?를 기준으로 세움.
        if(quiz[0] - '0' >= 0 && quiz[0] - '0' <= 9) //숫자로 변형한 값이 0~9사이 인가.-> 참이면 숫자
        {
            //해당 포켓몬 이름 저장
            results.push_back(indexkey[stoi(quiz)-1]);
        }
        else
        {
            // Find 함수를 이용해서 해당 포켓몬 번호 저장
            auto it = namekey.find(quiz);
            results.push_back(to_string(it->second + 1));
        }
    }
  
    for(int i = 0 ; i < M ; i ++)
    {
        cout << results[i] << "\n";
    }
    return 0;
}