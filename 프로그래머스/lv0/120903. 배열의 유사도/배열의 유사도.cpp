#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    //같은 원소의 개수를 return

    for_each(s2.begin(), s2.end(),
        [&](string s) { if (find(s1.begin(), s1.end(), s) != s1.end()) answer++; });
        
    return answer;
}