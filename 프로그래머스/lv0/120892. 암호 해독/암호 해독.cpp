#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    
    //code의 배수번째 글자만 진짜 암호
    for(int i = 1 ; i*code <= cipher.length(); i++)
    {
        answer += cipher[i*code - 1];
    }
    
    return answer;
}