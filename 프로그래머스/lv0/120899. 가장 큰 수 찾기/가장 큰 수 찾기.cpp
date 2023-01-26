#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    
    //가장 큰 수와 그 수의 인덱스
    int Max = *max_element(array.begin(),array.end());
    answer.push_back(Max);
    answer.push_back(find(array.begin(),array.end(), Max) - array.begin());
    
    return answer;
}