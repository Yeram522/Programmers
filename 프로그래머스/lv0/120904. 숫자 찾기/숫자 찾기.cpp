#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int num, int k) {
    int answer = 0;
    
    //to_string을 이용하면 바로 int를  string으로 바꿀 수 있다.
    string strNum = to_string(num);
    
    answer = strNum.find(to_string(k)) == string::npos ? -1 : strNum.find(to_string(k))+1;
    
    return answer;
}