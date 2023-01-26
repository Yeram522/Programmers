#include <string>
#include <vector>


using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    size_t pos = 0;
    
    for(auto str : my_string)
    {  
        const char* ch = letter.c_str();
        if (str == ch[0])
            continue;
        
        answer += str;
    }
    
    return answer;
}