#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string rsp) {
    string answer = "";
    //가위 2
    //바위 0
    //보 5
    vector<char> rspL = {'2','0','5'};
    vector<char> wrspL = {'0','5','2'};
    
    for(auto ca : rsp)
    {
        answer += wrspL[find(rspL.begin(), rspL.end(),ca) - rspL.begin()];
    }
    return answer;
}