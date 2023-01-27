#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    //1.한번만 등장하는 문자를 vector에 push_back
    //2. sort(Vec)
    
    for_each(s.begin(), s.end(),[&](char ch)
             {
                 int count = count_if(s.begin(),s.end(),[=](char c){ return c == ch;});
                 if(count == 1)
                     answer += ch;  
             });
    
    sort(answer.begin(),answer.end());
    
    return answer;
}