#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    //한판에 7조각
    answer = n%7 == 0 ? n/7 : n/7 + 1;
    return answer;
}