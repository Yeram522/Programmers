#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string before, string after) {
    int answer = 0;
    
    //구성요소가 같은가.-> 공평하게 정렬을 해서 같은지 비교하면 됨/
    vector<char> vBefore(before.begin(), before.end());
    vector<char> vAfter(after.begin(), after.end());
    
    sort(vBefore.begin(), vBefore.end());
    sort(vAfter.begin(), vAfter.end());
    
    string sBefore(vBefore.begin(), vBefore.end());
    string sAfter(vAfter.begin(), vAfter.end());
    
    answer = sBefore == sAfter ? 1 : 0;
    return answer;
}