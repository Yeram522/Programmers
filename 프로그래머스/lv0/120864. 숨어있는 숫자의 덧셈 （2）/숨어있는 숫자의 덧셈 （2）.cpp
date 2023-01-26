#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    vector<char> vString(my_string.begin(), my_string.end());
    vector<string> vInt;
    // 문자를 기준으로 divide
    size_t pos = 0;
    vector<char>::iterator iter;

    while ((iter = find_if(vString.begin(), vString.end(), [=](char ch) { return ch < '0' || ch > '9'; })) != vString.end())
    {
        string str(vString.begin(), iter);

        if (isdigit(str[0]))
            answer += stoi(str);

        vString.erase(vString.begin(), iter + 1);    
    }
    string str(vString.begin(), vString.end());

    if (isdigit(str[0]))
        answer += stoi(str);

    return answer;
}