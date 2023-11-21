// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    string sentence;
    
    string result;
    
    getline(cin, sentence); //공백 포함 string 입력 받기
    
    // 조건 : 소문자, 대문자가 아닌 문자는 그대로 남아 있어야 한다.
    
    for(auto word : sentence)
    {
        int ascii = int(word);
        int shift = ascii + 13;
        if(ascii >= 65 && ascii <= 90) // 대문자 혹은 소문자 일 경우 13칸 미뤄준다.
        {
            
            result += char(shift > 90 ? shift - 26 : shift );
        }
        else if(ascii >= 97 && ascii <= 122)
        {
            result += char(shift > 122 ? shift - 26 : shift );
        }
        else
        {
            result += word;
        }
    }
    
    cout << result;
    return 0;
}