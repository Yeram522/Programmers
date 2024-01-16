// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

//#16637: 괄호 추가하기
int N;
string S;
int ret = -987654321;//최대값 구하기

vector<char> oper_str;
vector<int> num;

int oper(int i, char c, int j)
{
    switch(c)
    {
        case '*':
            return i * j;
        case '-':
            return i - j;
        case '+':
            return i + j;
    }
    
    return 0;
}

void go(int here, int _num) //누적합합
{
    //기저 조건
    if(here == num.size() - 1)
    {
        ret =  max(ret, _num);
        return;
    }
    
    go(here + 1, oper(_num,oper_str[here],num[here + 1]));
    
    if(here + 2 <= num.size() - 1)
    {
        int temp = oper(num[here + 1], oper_str[here + 1], num[here+2]);
        go(here + 2, oper(_num, oper_str[here], temp));
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //input
    cin >> N;
    cin >> S;
    
    for(int i = 0; i < N; i++)
    {
        //숫자와 부호를 따로 저장한다.
        if(i%2 ==0){ num.push_back(S[i]- '0');}
        else
            oper_str.push_back(S[i] );
            
    }

    go(0, num[0]);

    cout << ret << "\n";
    return 0;
}