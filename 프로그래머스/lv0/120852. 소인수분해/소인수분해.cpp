#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int target = n;
    int prime = 2;
    while(target != 1)
    {
        if(target%prime == 0)
        {
            answer.push_back(prime);
            target /= prime;
        }
        else
            prime++;
    }
    
    sort(answer.begin(), answer.end());
    
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}