#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    //1. 가장큰 양의 정수 2개 곱하기
    //2. 절댓값이 가장 큰 양의 정수 2개 곱하기
    //둘중 비교하여 큰 값이 정답
    
    
    //sorting
    sort(numbers.begin(), numbers.end());
    
    int Max = numbers[0]*numbers[1];
    int Min = numbers[numbers.size()-1]*numbers[numbers.size()-2];
    
    answer = Max >= Min ? Max : Min;
    return answer;
}