#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    for_each(keyinput.begin(), keyinput.end(),[&](string command)
             {
                 //[0] * [1] 크기
                 if(command == "left")
                         answer[0] -= (answer[0]-1 >= (board[0]/2)*-1) ? 1 : 0;
                 else if(command == "right")  
                         answer[0] += (answer[0]+1 <= board[0]/2) ? 1 : 0;
                 else if(command == "up")  
                          answer[1] += (answer[1]+1 <= board[1]/2) ? 1 : 0;
                 else if(command == "down")  
                         answer[1] -= (answer[1]-1 >= (board[1]/2)*-1) ? 1 : 0;
                     
               
             });
    return answer;
}