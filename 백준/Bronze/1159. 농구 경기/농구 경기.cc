// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int pCount; // 입력받을 사람의 수
    vector<string> pList; //선수 리스트
    int FistNameCountList[26] = {0,};
    vector<char> results;
    // 0. Input
    cin >> pCount;
    
    for(int i = 0; i < pCount ; i ++)
    {
        string name;
        cin >> name;
        
        pList.push_back(name);
    }
    
    // 1. 성의 첫글자의 개수를 카운팅 및 저장
    for(int i = 0 ; i < pList.size(); i++)
    {
        int targetIndex = int(pList[i][0]) - 97; // 아스키코드로 계산하여 Index로 변환
        FistNameCountList[targetIndex] ++; // 개수 증감
        
        // 해당 알파벳의 개수가 5개 이상일 경우  results 에 추가.
        if(FistNameCountList[targetIndex] == 5) // 중복되지 않게 하기 위해서 등호 사용
        {
            results.push_back(pList[i][0]);
        }
    }
    
    // 2. results 출력
    if(results.size() == 0)
    {
        cout<< "PREDAJA";
        return 0;
    }
       
     sort(results.begin(), results.end());
 
    for(auto result : results)
    {
        cout<< result;
    }
    
    return 0;
}