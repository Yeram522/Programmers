#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    
    for(auto num : numlist)
    {
        if(num%n != 0) continue;
        answer.push_back(num);
    }
    return answer;
}