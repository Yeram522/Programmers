#include <string>
#include <vector>

using namespace std;

int measure(int n)
{
   int count = 0;
    //약수 개수 구하기
    for(int i = 1; i*i <= n; i++)
    {
        if(i*i ==n)
            count++;
        else if( n%i == 0)
            count +=2;
    }
    
    return count;
}

int solution(int n) {
    int answer = 0;
    
    while(n > 0)
    {
        if(measure(n)>=3)
            answer ++;
        
        n--;
    }
    
    return answer;
}