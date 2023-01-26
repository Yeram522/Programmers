#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    //3,6,9가 들어가있으면 answer이 하나씩 증감.
    string strOrder = to_string(order);
    
    for_each(strOrder.begin(), strOrder.end(), [&](char ch){ if(ch == '3' || ch == '6' || ch == '9') answer++;});
    return answer;
}