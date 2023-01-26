#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;

    int numer = numer1*denom2 +numer2*denom1;
    int denom = denom1*denom2;
    
    //두 정수의 최대 공약수 구하기.
    int x = numer;
    int y = denom;
    int r = 1;
    while(x%y != 0)
    {
        r = x%y;
        x = y;
        y = r;
    }
    
    answer.push_back(numer/y);
    answer.push_back(denom/y);
    
    

    return answer;
}