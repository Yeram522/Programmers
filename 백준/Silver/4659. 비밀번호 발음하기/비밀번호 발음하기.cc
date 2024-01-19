// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
vector<pair<string,bool>> password;

vector<char> vowel = {'a','e','i','o','u'};

bool check(string wd)
{
    bool flag = false;
    
    //1.모음이 1개 이상 있는가?
    for(int i = 0; i < 5;i++)
    { if(wd.find(vowel[i]) != string::npos) {flag = true;} }
    
    if(!flag) 
    {
        return flag;
    }
    
    //2. 모음 및 자음이 연속 3개인가?
    int count = 0;
    bool prev;
    char prevword = wd[0];
    for(int i = 0; i < wd.size(); i++)
    {
        if(i!=0) //같은 글자 연속 체크
        {
            if(prevword == wd[i] && wd[i] != 'e'&& wd[i] != 'o' ) 
            {
                flag = false;
            
                return flag;
            }
            prevword = wd[i];
        }
         //모음?
        bool isV = find(vowel.begin(),vowel.end(), wd[i]) != vowel.end() ? true : false;
        

         //count가 0일 때
        if(count == 0 || prev == isV )
        { 
            count++; 
        }
        else 
        {
            count = 1;
        }
        
        prev = isV;
        
        if(count < 3 ) continue;
        
        flag = false;
        return false;
    }
    
    flag = true;
    
    return flag;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string _input = "";
    
    while(true)
    {
        cin >> _input;
        if(_input == "end") break;
        password.push_back({_input,check(_input)});
    }
    
    
    
    for(auto word : password)
    {
        cout << "<" << word.first << "> " << "is ";
        if(!word.second)
            cout << "not ";
        cout <<"acceptable." << endl;
    }
    
    return 0;
}