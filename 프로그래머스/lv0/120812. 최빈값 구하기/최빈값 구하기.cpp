#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    vector<int> uniqlist = array;
    
    vector<int> countL;
    
    //정렬
    sort(uniqlist.begin(), uniqlist.end());
    //중복제거
    uniqlist.resize( unique(uniqlist.begin(), uniqlist.end()) - uniqlist.begin() );
    //값의 개수
    for(auto num : uniqlist)
    {
        countL.push_back(count(array.begin(),array.end(),num));
    };

    //최빈값
    int maxC = *max_element(countL.begin(),countL.end());
    
    int max_index = max_element(countL.begin(), countL.end()) - countL.begin();
        
    answer = count(countL.begin(),countL.end(),maxC) > 1 ? -1 : uniqlist[max_index];
    
    return answer;
}