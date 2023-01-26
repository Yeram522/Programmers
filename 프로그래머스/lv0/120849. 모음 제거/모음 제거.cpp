#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string) {
    string answer = "";
    
    my_string.erase(remove_if(my_string.begin(),my_string.end(),[=](char n){ return n == 'a';}), my_string.end());
    my_string.erase(remove_if(my_string.begin(),my_string.end(),[=](char n){ return n == 'e';}), my_string.end());
    my_string.erase(remove_if(my_string.begin(),my_string.end(),[=](char n){ return n == 'i';}), my_string.end());
    my_string.erase(remove_if(my_string.begin(),my_string.end(),[=](char n){ return n == 'o';}), my_string.end());
    my_string.erase(remove_if(my_string.begin(),my_string.end(),[=](char n){ return n == 'u';}), my_string.end());
    
    answer = my_string;
    return answer;
}