#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    int tempi = 0;
    
    if(direction == "left")
    {
        tempi = numbers[0];
        answer = vector<int>(numbers.begin()+1, numbers.end() );
        answer.push_back(tempi);
        
    }
    else
    {
        tempi = numbers[numbers.size()-1];
        answer = vector<int>(numbers.begin(), numbers.end()-1);
        answer.insert(answer.begin(), tempi);
        
        
    }

    
    return answer;
}