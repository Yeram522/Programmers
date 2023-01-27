#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    //나머지 한변이 될 수 있는 정수의 개수.
    //가장 긴변의 길이는 다른 두 변의 길이의 합보다 작아야 한다.
    
    sort(sides.rbegin(), sides.rend());
    
    int min = sides[0] - sides[1]; //3, 6일때 6이 가장 긴 변일 경우 6 < 3 + a -> 3 < a 
    int max = sides[0] + sides[1];
    // a가 가장 긴변일 경우 3 + 6 > a
    answer = max - min - 1;
    return answer;
}