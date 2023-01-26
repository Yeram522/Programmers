#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    //1~n까지의 숫자중 나누어떨어지는 것을 pushback

    for(int i = 1; i <= n ; i++)
    {
        if(n%i == 0) answer.push_back(i);
    }

    
    return answer;
}