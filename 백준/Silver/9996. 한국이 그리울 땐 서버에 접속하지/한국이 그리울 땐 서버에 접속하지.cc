// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

vector<string> results;

vector<string> split(string input, string delimiter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

bool isCorrect(string pattern, string filename)
{
    vector<string> splitedpattern = split(pattern, "*");
    
    //1. * 앞의 패턴이 맞는가.
    auto result = filename.find(splitedpattern[0]);
    if(result == string::npos || result != 0)
    {
        return false;
    }
        
    
    //2. * 뒤의 패턴이 맞는가.
    // 앞에서 패턴 처리한 filename은 지운다.
    filename = filename.substr(result + splitedpattern[0].size());
    if(filename.size() == 0) return false;
    result = filename.find(splitedpattern[1], filename.size() - splitedpattern[1].size());
    if(result == string::npos || result != filename.size() - splitedpattern[1].size())
    {
        return false;
    }
        
    return true;
    
}

int main() {
    int N; // 파일 개수
    string pattern;
    vector<string> filenames;
   
    // Input
    cin >> N;
    cin >> pattern;
    for(int i = 0; i < N ; i++)
    {
        string name;
        cin >> name;
        filenames.push_back(name);
    }
    
    for(auto filename : filenames)
    {
        results.push_back(isCorrect(pattern,filename) ? "DA" : "NE");
    }
    
    //print result
    for(auto re : results)
    {
        cout<< re << endl;
    }
    return 0;
}