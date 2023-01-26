#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for_each(my_string.begin(), my_string.end(), [&](char ch){ answer += ch < 'a' || ch > 'z' ? ch - 'A' +'a' : ch; 
                                                             });
    
    sort(answer.begin(),answer.end());
    return answer;
}