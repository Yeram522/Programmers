#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    string strAge = to_string(age);
    
    vector<int> agesNum;
    
    for(int i = 0; i < strAge.length(); i++)
    {
        answer.push_back(49+(int)strAge[i]);
    }
    return answer;
}