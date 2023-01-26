#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    //string은 연산자 사용이 가능하다.
    for(auto str : my_string)
    {
        for(int i = 0; i < n ;i++)
            answer += str;
    }
    return answer;
}