#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i *i <= n ; i++)
    {
        if
            (i*i == n) answer++;
        else if 
            (n%i == 0) answer += 2;
    }
    
    return answer;
}