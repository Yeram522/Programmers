#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
     
    answer = count_if(array.begin(), array.end(), [=](int num){return height<num;});
    
    return answer;
}