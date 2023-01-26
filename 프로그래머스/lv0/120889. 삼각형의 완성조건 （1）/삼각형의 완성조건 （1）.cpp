#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    //가장 긴 변의 길이 < 다른 두변의 길이의 합 
    sort(sides.rbegin(), sides.rend());
    answer = sides[0] < sides[1] + sides[2] ? 1 : 2;
    
    return answer;
}