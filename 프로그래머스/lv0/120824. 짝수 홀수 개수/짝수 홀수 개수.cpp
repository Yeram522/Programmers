#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    //짝수
    answer.push_back(0);
    
    //홀수
    answer.push_back(0);
    
    for(auto num : num_list)
    {
        answer[num%2 == 0 ? 0 : 1]++;
    }
    return answer;
}