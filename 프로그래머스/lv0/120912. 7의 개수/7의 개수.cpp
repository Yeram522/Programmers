#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    //7이 총 몇개 있는가??
    for_each(array.begin(), array.end(),
            [&](int n){
                string str = to_string(n);
                answer += count(str.begin(),str.end(),'7');
            });
    return answer;
}