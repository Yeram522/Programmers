#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string letter) {
    string answer = "";
    
    vector<string> morse
    {
        ".-","-...","-.-.","-..",".","..-.",
        "--.","....","..",".---","-.-",".-..",
        "--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-",
        "-.--","--.."
    }; //a = 97
    
    //공백에 따른 문자열 분리
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = letter.find(space_delimiter)) != string::npos) {
        words.push_back(letter.substr(0, pos));
        letter.erase(0, pos + space_delimiter.length());
    }
    words.push_back(letter);
    
    for(auto word : words)
    {
        int idx = find(morse.begin(), morse.end(), word) - morse.begin();
        answer += (idx + 97);
    }
    
    
    return answer;
}