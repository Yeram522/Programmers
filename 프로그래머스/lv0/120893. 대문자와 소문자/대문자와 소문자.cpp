#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string) {
    string answer = "";

    for_each(my_string.begin(), my_string.end(),
        [&](char ch) {
            answer += ch >= 65 && ch <= 90 ? ch + 32 : ch - 32;
        });
    return answer;
}