#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    string sAnswer;
     vector<string> sNumbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
    string tmp;
    for_each(numbers.begin(), numbers.end(),[&](char ch)
             {
                 tmp += ch;
                 if(find(sNumbers.begin(),sNumbers.end(),tmp) == sNumbers.end()) return;
                 //있다면
                 sAnswer += to_string(find(sNumbers.begin(),sNumbers.end(),tmp)-sNumbers.begin());
                 tmp = "";
                 
             });
    
    answer = stoll(sAnswer);
    return answer;
}