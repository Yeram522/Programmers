// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // STL 함수를 사용한다.
    string word;
    
    cin >> word;
    
    string rword = word;
    reverse(rword.begin(), rword.end());
    if(word.compare(rword) == 0)
        cout << 1;
    else
        cout << 0;
    
    return 0;
}