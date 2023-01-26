#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    //1. 오름차순 정렬
    sort(array.begin(), array.end());
    //2. 중앙값.
    answer = array[array.size()/2];
    return answer;
}