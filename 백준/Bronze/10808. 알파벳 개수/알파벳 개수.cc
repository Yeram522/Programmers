// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;


int main() {
    char words[100]; // 문제 제시 : 단어의 길이가 100을 넘지 않음.
    //크기 고정이므로 정적배열 선언
    int alphacount[26] = {0,};
    
    //1. input
    scanf("%s", &words);

    
    //2. 
    for(int i = 0; i < strlen(words); i++)
    {
        alphacount[int(words[i])-97] ++;
    }
    
    //3.
    for(int i = 0 ; i < 26; i++)
    {
       cout<< alphacount[i] << " ";
    }
    
    
    
    return 0;
}