#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, int t) {
    int answer = 0;
    
    //n의 t+1 제곱
    answer = n * pow(2,t);
    
    return answer;
}