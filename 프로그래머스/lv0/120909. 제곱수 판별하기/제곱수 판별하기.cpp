#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    //n이 어떤 수 k의 제곱수 인지 판별.
    answer = (int)sqrt(n)*(int)sqrt(n) == n ? 1 : 2;
    return answer;
}