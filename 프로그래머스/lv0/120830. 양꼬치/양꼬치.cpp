#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    //전체 가격 - 서비스 받을 가격.
    
    //서비스 음료 개수
    int drink = n/10;
    
    answer = n*12000 + 2000*k - drink*2000;
    return answer;
}