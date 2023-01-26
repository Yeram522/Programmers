#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for(auto str : my_string)
    {
        if(str>=48 && str <=57)
            answer += str-48;
    }
    return answer;
}