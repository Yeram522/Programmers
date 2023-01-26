#include <string>
#include <vector>

using namespace std;

int chickCount(int chicken)
{
    if(chicken < 10) return 0;
    
    int value = chicken/10;
    return value + chickCount(chicken%10 + value);
}

int solution(int chicken) {
    int answer = -1;
    
    answer = chickCount(chicken); //서비스 치킨의 수
    
    return answer;
}